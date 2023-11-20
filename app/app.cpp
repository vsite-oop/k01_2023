#include "app.h"


void divisible_count(int* n, int x, int* n2, int y)
{
	for (int i = 0; i < x; ++i)
	{
		int brojac = 0;
		for (int j = 0; j < y; ++j)
		{
			if (n[i] % n2[j] == 0)
				++brojac;
		}
		n[i] = brojac;
	}
}
oop::oop(int g, int br_studenata) : st(br_studenata), godina(g) {};
nwp::nwp(int g, int br_studenata) : st(br_studenata), godina(g) {};

std::string oop::title() { return "oop"; };
uint16_t oop::students() { return st; };
uint16_t oop::year() { return godina; };


std::string nwp::title() { return "nwp"; };
uint16_t nwp::students() { return st; };
uint16_t nwp::year() { return godina; };

std::unique_ptr<course> course_factory(int predmet, int godina, int br_studenata)
{
	if (predmet == 1)
		return std::make_unique<oop>(godina, br_studenata);
	else if (predmet == 2)
		return std::make_unique<nwp>(godina, br_studenata);
	else
		return nullptr;
}
int cards_value(const std::string& s)
{
	int vrijednost = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'T')
			vrijednost += 10;
		else if (s[i] == 'J')
			vrijednost += 11;
		else if (s[i] == 'Q')
			vrijednost += 12;
		else if (s[i] == 'K')
			vrijednost += 13;
		else  if (s[i] == 'A')
			vrijednost += 1;
		else if (s[i] == '1')
			return -1;
		else if (isdigit(s[i]))
			vrijednost += (s[i] - '0');
		else
			return -1;
	}
	return vrijednost;
}

polyline::polyline(int size) : duljina(size), niz(new vertex[duljina]) {};
polyline::polyline(const polyline& other) : duljina(other.duljina), niz(new vertex[duljina])
{
	for (int i = 0; i < duljina; ++i)
	{
		niz[i] = other.niz[i];
	}
}
polyline::~polyline()
{
	delete[] niz;
}
void polyline::add(const vertex& v)
{
	niz[indeks++] = v;
}
double izracun(const vertex& v1, const vertex& v2)
{
	int dx = v2.x - v1.x;
	int dy = v2.y - v1.y;
	return sqrt(dx * dx + dy * dy);
}
double polyline::length()
{
	double d = 0;
	for (int i = 0; i < duljina - 1; ++i)
	{
		d += izracun(niz[i], niz[i + 1]);
	}
	return d;
}

