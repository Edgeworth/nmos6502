#ifndef NMOS6502_MEMORY_HPP_
#define NMOS6502_MEMORY_HPP_
#include "nmos6502/common.hpp"

namespace nmos6502 {

	typedef uint8 (*readCB)(uint8* m, uint16 addr, void* userdata);
	typedef void (*writeCB)(uint8* m, uint16 addr, uint8 data, void* userdata);

	class Memory {
	public:
		uint8 m[1<<16]; ///< 64 KB of memory


		/** \brief Read 1 byte of memory observing any memory mapping.
		 *
		 * \param addr Address in memory to read.
		 * \return Data located at \a addr.
		 */
		uint8 r8(uint16 addr);
		/** \brief Write 1 byte of memory observing any memory mapping.
		 *
		 * \param addr Address in memory to read.
		 * \param data Data to write at \a addr
		 */
		void w8(uint16 addr, uint8 data);

		/** \brief Set a read callback for a range.
		 *
		 * Sets the read callback for all addresses between \a start and \a end inclusive.
		 * Use this to implement memory mapped hardware, mirroring, or similar.
		 *
		 * \param start Beginning address of range.
		 * \param end Ending address of range. Included in the range.
		 * \param cb Read callback.
		 * \param userdata User data, defaults to NULL.
		 */
		void setReadCB(uint16 start, uint16 end, readCB cb, void* userdata = NULL);

		/** \brief Set a read callback.
		 *
		 * Sets the read callback for the address \a addr specified.
		 * Use this to implement memory mapped hardware, mirroring, or similar.
		 *
		 * \param addr Address to set callback for.
		 * \param cb Read callback.
		 * \param userdata User data, defaults to NULL.
		 */
		void setReadCB(uint16 addr, readCB cb, void* userdata = NULL);

		/** \brief Set a write callback for a range.
		 *
		 * Sets the write callback for all addresses between \a start and \a end inclusive.
		 * Use this to implement memory mapped hardware, mirroring, or similar.
		 *
		 * \param start Beginning address of range.
		 * \param end Ending address of range. Included in the range.
		 * \param cb Write callback.
		 * \param userdata User data, defaults to NULL.
		 */
		void setWriteCB(uint16 start, uint16 end, writeCB cb, void* userdata = NULL);

		/** \brief Set a write callback.
		 *
		 * Sets the write callback for the address \a addr specified.
		 * Use this to implement memory mapped hardware, mirroring, or similar.
		 *
		 * \param addr Address to set callback for.
		 * \param cb Write callback.
		 * \param userdata User data, defaults to NULL.
		 */
		void setWriteCB(uint16 addr, writeCB cb, void* userdata = NULL);

	private:
		readCB r_cb[1<<16];
		void* r_cb_udata[1<<16];
		writeCB w_cb[1<<16];
		void* w_cb_udata[1<<16];
	};
}

#endif
