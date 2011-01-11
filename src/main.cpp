#include <cstdio>
#include "nmos6502/cpu.hpp"
#include "nmos6502/disassemble.hpp"
#include "boost/format.hpp"
#include <sys/time.h>
#include <termios.h>

using namespace nmos6502;
const double CLOCK = 10000; //MHz

class Timer {
public:
	Timer() {reset();}
	void reset() {
		gettimeofday(&start, NULL);
	}

	double elapsed() {
		timeval end;
		gettimeofday(&end, NULL);
		return double(end.tv_sec-start.tv_sec)+double(end.tv_usec-start.tv_usec)/1000000.0;
	}

private:
	timeval start;
};


uint8 readChar(uint8* m, uint16 addr, void* userdata) {
	CPU* cpu = (CPU*)userdata;
	int c = getchar();

	if (c == 0xA) c = 0xD;
	if (c == EOF) {
		set(cpu->P, FCARRY, 0);
		return 0;
	} else {
		set(cpu->P, FCARRY, 1);
		return c;
	}
}

void writeChar(uint8* m, uint16 addr, uint8 data, void* userdata) {
	if (data == 0xD) data = 0xA;
	printf("%c", data);
}

int main() {
	termios attr;
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &attr);

	int size = 65536;
	FILE* rom = fopen("basic.rom", "r");
	char buf[65536];
	fread(buf, 1, 65536, rom);

	CPU cpu;
	cpu.m.load(0x0, 65536, buf);
	cpu.m.setWriteCB(0xF001, writeChar, &cpu);
	cpu.m.setReadCB(0xF004, readChar, &cpu);
	cpu.reset();

	Timer timer;
	bool br = false;
	while (br == false || (getchar()||true)) {
		timer.reset();
		//if (cpu.PC == 0xda82) br = true;
		//if (cpu.PC == 0xc0a2) br = true;
		if (br) {
			printf("%s\n", (boost::format("A:$%x X:$%x Y:$%x P:$%x SP:$%x PC:$%x cycles:%d")%
						int(cpu.A)%int(cpu.X)%int(cpu.Y)%
						int(cpu.P)%int(cpu.SP)%int(cpu.PC)%cpu.cycles).str().c_str());
			printf("%s\n", disassemble(cpu.m.m+cpu.PC).c_str());
		}

		int cycles = cpu.step();

		double time_sleep = double(cycles)/CLOCK-timer.elapsed()*1000000.0;
		if (time_sleep > 0)
			usleep(time_sleep);
	}
}
