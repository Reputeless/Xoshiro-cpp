
# include <iostream>
# include <random>
# include "XoshiroCpp.hpp"

int main()
{
	using namespace XoshiroCpp;

	std::cout << "# Initialize with a default 64-bit seed\n";
	{
		Xoshiro256PlusPlus rng;
		std::cout << rng() << '\n'
				  << rng() << '\n'
				  << rng() << '\n';
	}

	std::cout << "\n# Initialize with a 64-bit seed\n";
	{
		constexpr std::uint64_t seed = 777;
	
		Xoshiro256PlusPlus rng(seed);
		std::cout << rng() << '\n'
				  << rng() << '\n'
				  << rng() << '\n';
	}

	std::cout << "\n# Initialize with a given state\n";
	{
		// poorly distributed
		constexpr std::uint64_t seed0 = 0;
		constexpr std::uint64_t seed1 = 0;
		constexpr std::uint64_t seed2 = 1;
		constexpr std::uint64_t seed3 = 1;
		constexpr Xoshiro256PlusPlus::state_type state =
		{
			seed0,
			seed1,
			seed2,
			seed3
		};

		Xoshiro256PlusPlus rng(state);
		std::cout << rng() << '\n'
				  << rng() << '\n'
				  << rng() << '\n';
	}

	std::cout << "\n# Initialize with a given state (SplitMix64 is used for entropy)\n";
	{
		// poorly distributed
		constexpr std::uint64_t seed0 = 0;
		constexpr std::uint64_t seed1 = 0;
		constexpr std::uint64_t seed2 = 1;
		constexpr std::uint64_t seed3 = 1;
		constexpr Xoshiro256PlusPlus::state_type state =
		{
			SplitMix64(seed0)(),
			SplitMix64(seed1)(),
			SplitMix64(seed2)(),
			SplitMix64(seed3)()
		};

		Xoshiro256PlusPlus rng(state);
		std::cout << rng() << '\n'
				  << rng() << '\n'
				  << rng() << '\n';
	}

	std::cout << "\n# Generate double in the range of [0.0, 1.0)\n";
	{
		Xoshiro256PlusPlus rng(111);
		std::cout << DoubleFromBits(rng()) << '\n'
				  << DoubleFromBits(rng()) << '\n'
				  << DoubleFromBits(rng()) << '\n';
	}

	std::cout << "\n# Generate int in the range of [1, 6]\n";
	{
		Xoshiro256PlusPlus rng(222);
		std::uniform_int_distribution<int> dist(1, 6);
		std::cout << dist(rng) << '\n'
				  << dist(rng) << '\n'
				  << dist(rng) << '\n';
	}
}
