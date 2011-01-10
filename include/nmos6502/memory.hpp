#ifndef NMOS6502_MEMORY_HPP_
#define NMOS6502_MEMORY_HPP_
#include "nmos6502/common.hpp"

namespace nmos6502 {

	typedef uint8 (*readCB)(uint8* m, uint16 addr, void* userdata);
	typedef void (*writeCB)(uint8* m, uint16 addr, uint8 data, void* userdata);

	class Memory {
	public:
		uint8 m[1<<16]; ///< 64 KB of memory

		Memory();

		/** \brief Load data into memory.
		 *
		 * Loads data into memory, does not observe memory mapping. Useful to load code into memory.
		 *
		 * \param start Start of where to load data.
		 * \param size Size of data to load, in bytes.
		 * \param data Pointer to data
		 */
		void load(uint16 start, int size, void* data);

		/** \brief Set the IRQ vector. Observes memory mapping.
		 *
		 * \param addr Address to set IRQ vector to
		 */
		void setIRQ(uint16 addr);

		/** \brief Set the NMI vector.  Observes memory mapping.
		 *
		 * \param addr Address to set NMI vector to
		 */
		void setNMI(uint16 addr);

		/** \brief Set the reset vector.  Observes memory mapping.
		 *
		 * \param addr Address to set reset vector to
		 */
		void setReset(uint16 addr);

		/** \brief Get the IRQ vector. Observes memory mapping.
		 *
		 * \return IRQ vector.
		 */
		uint16 getIRQ();

		/** \brief Get the NMI vector.  Observes memory mapping.
		 *
		 * \return NMI vector.
		 */
		uint16 getNMI();

		/** \brief Get the reset vector.  Observes memory mapping.
		 *
		 * \return reset vector.
		 */
		uint16 getReset();

		/** \brief Read 1 byte of memory observing any memory mapping.
		 *
		 * \param addr Address in memory to read.
		 * \return Data located at \a addr.
		 */

		uint8 r8(uint16 addr);

		/** \brief Write 1 byte of memory observing any memory mapping.
		 *
		 * \param addr Address in memory to write.
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
