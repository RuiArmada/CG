#ifndef DIST
#define DIST

#include <random>

template <class D>

class Dist final {
	private:
		auto static inline engine = stf::mt19937{ std::random_device{}() };

		mutable std::uniform_real_distribution<D> m_uniform_dist;

	public:
		constexp Dist(D min, D max): m_uniform_dist{min,max} {}

		auto constexp operator()() const -> D {
			return m_uniform_dist(engine);
		}
};

#endif //DIST