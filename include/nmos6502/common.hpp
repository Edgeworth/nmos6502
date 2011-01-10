#ifndef NMOS6502_COMMON_HPP_
#define NMOS6502_COMMON_HPP_
#include <cstring>
#include "boost/cstdint.hpp"

namespace nmos6502 {

	typedef boost::uint8_t uint8;
	typedef boost::int8_t int8;
	typedef boost::uint16_t uint16;
	typedef boost::int16_t int16;


	/** \brief Set bit in position \a p
	 *
	 * \param x Integer to set bit in
	 * \param p Position of bit to be set (starting from 0)
	 */
	template<typename T>
	inline void set(T& x, int p) {x |= 1<<p;}

	/** \brief Unset bit in position \a p
	 *
	 * \param x Integer to unset bit in
	 * \param p Position of bit to be unset (starting from 0)
	 */
	template<typename T>
	inline void unset(T& x, int p) {x &= ~(1<<p);}

	/** \brief Check if bit in \a x at position \a p is set
	 *
	 * \param x Integer to check bit in
	 * \param p Position of bit to check (starting from 0)
	 */
	template<typename T>
	inline bool isset(T x, int p) {return x&(1<<p);}

	/** \brief Set the high byte of \a x to \a v.
	 *
	 * \param x Reference to the 2 byte value to set the high byte of.
	 * \param v 1 byte value to set the high byte of \a x to.
	 */
	inline void sethi(uint16& x, uint8 v) {x = (v<<8) | (x&0xFF);}

	/** \brief Set the low byte of \a x to \a v.
	 *
	 * \param x Reference to the 2 byte value to set the low byte of.
	 * \param v 1 byte value to set the low byte of \a x to.
	 */
	inline void setlo(uint16& x, uint8 v) {x = v | (x&0xFF00);}

	/** \brief Get the high byte of \a x to \a v.
	 *
	 * \param x 2 byte value to get the high byte of.
	 * \return High byte of \a x.
	 */
	inline uint8 gethi(uint16 x) {return x>>8;}

	/** \brief Get the low byte of \a x to \a v.
	 *
	 * \param x 2 byte value to get the low byte of.
	 * \return Low byte of \a x.
	 */
	inline uint8 getlo(uint16 x) {return x;}

	/** \brief Joins a low byte and a high byte into a single 2 byte value
	 * \param lo Low byte.
	 * \param hi High byte.
	 * \return Joined 2 byte value
	 */
	inline uint16 join(uint8 lo, uint8 hi) {return lo | (hi<<8);}
}

#endif
