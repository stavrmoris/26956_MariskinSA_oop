template <typename back, typename fir, typename sec>
back average(fir const &a, sec const &b)
{
	back s = (a + b) / 2.0;
	return s;
}