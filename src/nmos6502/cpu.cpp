#include "nmos6502/cpu.hpp"
#include "nmos6502/instructions.hpp"

namespace nmos6502 {
	//Zero flag initially set to 1
	CPU::CPU() : A(0xAA), X(0), Y(0), SP(0), P(2), PC(0), cycles(0), _ready(false) {}

	int CPU::run(int min_cycles) {
		int executed_cycles = 0;
		while (executed_cycles < min_cycles) executed_cycles += step();
		return executed_cycles;
	}

	int CPU::step() {
		if (!_ready) reset(); //If the CPU isn't ready, reset it.
		int executed_cycles = opcodes[fetch()](*this);
		cycles += executed_cycles;
		return executed_cycles;
	}

	int CPU::irq() {
		if (isset(P, FINT)) return 0; //If IRQ's are being blocked, do nothing.
		push16(PC);
		push8(P);
		PC = m.getIRQ();
		set(P, FINT);
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

	int CPU::nmi() {
		push16(PC);
		push8(P);
		PC = m.getNMI();
		set(P, FINT);
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

	int CPU::reset() {
		_ready = true;
		cycles = 0;
		SP -= 3; //reset is implemented as a hacked brk instruction -- 3 stack pushes are done, but nothing is pushed.
		set(P, FINT);
		set(P, FBRK);
		PC = m.getReset();
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

	void CPU::push8(uint8 x) {
		m.w8(SP--, x);
	}

	void CPU::push16(uint16 x) {
		push8(gethi(x));
		push8(getlo(x));
	}

	uint8 CPU::pop8() {
		return m.r8(++SP);
	}

	uint16 CPU::pop16() {
		uint8 lo = pop8();
		uint8 hi = pop8();
		return join(lo, hi);
	}

	uint8 CPU::fetch() {
		return m.r8(PC++);
	}
}
