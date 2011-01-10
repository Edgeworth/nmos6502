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

	uint8 Memory::r8(uint16 addr) {
		if (r_cb[addr] == NULL) return m[addr];
		return r_cb[addr](m, addr, r_cb_udata[addr]);
	}

	void Memory::w8(uint16 addr, uint8 data) {
		if (w_cb[addr] == NULL) {
			m[addr] = data;
			return;
		}
		w_cb[addr](m, addr, data, w_cb_udata[addr]);
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
