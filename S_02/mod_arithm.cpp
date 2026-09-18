#include <random>
template <typename back, typename fir, typename sec>
back mod_average(fir const &a, sec const &b)
{
	static std::random_device seed; // Фиксируем сид
	static std::mt19937 gen(seed()); // Генератор псевдослучайных чисел
	static std::uniform_int_distribution<int> chance(0.0, 1.0); // Шанс 50/50
	static std::uniform_int_distribution<int> rand_add(0.0, 100.0); // Добавляем рандомное число от 0 до 100

	back res = (a + b) / 2.0;
	if (chance(gen) == 0.0)
	{
		res += rand_add(gen);
		return res;
	}
	return res;
}