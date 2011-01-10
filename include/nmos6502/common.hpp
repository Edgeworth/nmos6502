#ifndef NMOS6502_COMMON_HPP_
#define NMOS6502_COMMON_HPP_
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

	/** \brief Get bit in position \a p
	 *
	 * \param x Integer to get bit in
	 * \param p Position of bit to get (starting from 0)
	 */
	template<typename T>
	inline bool get(T x, int p) {return x&(1<<p);}

}

#endif
