#include <cstring>
#include "nmos6502/memory.hpp"

namespace nmos6502 {
	Memory::Memory() {
		for (int i = 0; i < (1<<16); ++i) {
			m[i] = 0;
			r_cb[i] = NULL;
			r_cb_udata[i] = NULL;
			w_cb[i] = NULL;
			w_cb_udata[i] = NULL;
		}
	}

	void Memory::load(uint16 start, int size, void* data) {
		memcpy(&m[start], data, size);
	}

	void Memory::setIRQ(uint16 addr) {
		w8(0xFFFE, getlo(addr));
		w8(0xFFFF, gethi(addr));
	}

	void Memory::setNMI(uint16 addr) {
		w8(0xFFFA, getlo(addr));
		w8(0xFFFB, gethi(addr));
	}

	void Memory::setReset(uint16 addr) {
		w8(0xFFFC, getlo(addr));
		w8(0xFFFD, gethi(addr));
	}

	uint16 Memory::getIRQ() {
		return join(r8(0xFFFE), r8(0xFFFF));
	}

	uint16 Memory::getNMI() {
		return join(r8(0xFFFA), r8(0xFFFB));
	}

	uint16 Memory::getReset() {
		return join(r8(0xFFFC), r8(0xFFFD));
	}

	void Memory::setReadCB(uint16 start, uint16 end, readCB cb, void* userdata) {
		for (int i = start; i <= end; ++i) {
			r_cb[i] = cb;
			r_cb_udata[i] = userdata;
		}
	}

	void Memory::setReadCB(uint16 addr, readCB cb, void* userdata) {
		r_cb[addr] = cb;
		r_cb_udata[addr] = userdata;
	}

	void Memory::setWriteCB(uint16 start, uint16 end, writeCB cb, void* userdata) {
		for (int i = start; i <= end; ++i) {
			w_cb[i] = cb;
			w_cb_udata[i] = userdata;
		}
	}

	void Memory::setWriteCB(uint16 addr, writeCB cb, void* userdata) {
		w_cb[addr] = cb;
		w_cb_udata[addr] = userdata;
	}

}
