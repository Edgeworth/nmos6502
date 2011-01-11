#include "nmos6502/cpu.hpp"
#include "nmos6502/instructions.hpp"

#include <cstdio>

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
		uint8 opcode = fetch();
		if (opcodes[opcode] == NULL) {
			printf("Unknown opcode: %d\n", opcode);
			exit(1);
		}
		int executed_cycles = opcodes[opcode](*this);
		cycles += executed_cycles;
		return executed_cycles;
	}

	int CPU::irq() {
		if (isset(P, FINT)) return 0; //If IRQ's are being blocked, do nothing.
		push16(PC);
		push8(P);
		PC = m.getIRQ();
		set(P, FINT, 1);
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

	int CPU::nmi() {
		push16(PC);
		push8(P);
		PC = m.getNMI();
		set(P, FINT, 1);
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

	int CPU::reset() {
		_ready = true;
		cycles = 0;
		SP -= 3; //reset is implemented as a hacked brk instruction -- 3 stack pushes are done, but nothing is pushed.
		set(P, FINT, 1);
		set(P, FBRK, 1);
		PC = m.getReset();
		cycles += 7; //IRQ overhead is 7 cycles
		return 7;
	}

}
