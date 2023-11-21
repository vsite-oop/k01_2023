#include "CppUnitTest.h"
#include "../app/app.h"
#include <numbers>

#include <numbers>
#include <type_traits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;

namespace all_tests
{
	TEST_CLASS(test_k01) 
	{
	public:

		// 10 bodova
		TEST_METHOD(test_01)
		{
			{
				int arr[]{ 15, 8, 30, 55, 12 };
				int div[]{ 3, 5 };
				divisible_count(arr, 5, div, 2);
				Assert::AreEqual(2, arr[0]);
				Assert::AreEqual(0, arr[1]);
				Assert::AreEqual(2, arr[2]);
				Assert::AreEqual(1, arr[3]);
				Assert::AreEqual(1, arr[4]);
			}
			{
				int arr[]{ 10, 20, 30, 40, 50, 60 };
				int div[]{ 2, 3, 4 };
				divisible_count(arr, 6, div, 3);
				Assert::AreEqual(1, arr[0]);
				Assert::AreEqual(2, arr[1]);
				Assert::AreEqual(2, arr[2]);
				Assert::AreEqual(2, arr[3]);
				Assert::AreEqual(1, arr[4]);
				Assert::AreEqual(3, arr[5]);
			}
		}

		// 12 bodova
		TEST_METHOD(test_02)
		{
			Assert::IsTrue(std::is_abstract_v<course>);
			Assert::IsTrue(std::is_same_v<uint16_t, decltype(1_us)>);

			auto c1 = course_factory(1, 2023, 16);
			Assert::AreEqual("oop"s, c1->title());
			Assert::AreEqual(16_us, c1->students());
			Assert::AreEqual(2023_us, c1->year());

			auto c2 = course_factory(2, 2024, 10);
			Assert::AreEqual("nwp"s, c2->title());
			Assert::AreEqual(10_us, c2->students());
			Assert::AreEqual(2024_us, c2->year());

			auto c3 = course_factory(3);
			Assert::IsNull(c3.get());
		}

		// 10 bodova
		TEST_METHOD(test_03)
		{
			Assert::AreEqual(10, cards_value("T"s));
			Assert::AreEqual(11, cards_value("J"s));
			Assert::AreEqual(12, cards_value("Q"s));
			Assert::AreEqual(13, cards_value("K"s));
			Assert::AreEqual(1, cards_value("A"s));
			Assert::AreEqual(26, cards_value("AKQ"s));
			Assert::AreEqual(30, cards_value("T8642"s));
			Assert::AreEqual(30, cards_value("357933"s));
			Assert::AreEqual(13, cards_value("6A6"s));
			Assert::AreEqual(-1, cards_value("5317"s));
			Assert::AreEqual(-1, cards_value("k47"s));
			Assert::AreEqual(-1, cards_value("JACK"s));
			Assert::AreEqual(0, cards_value(""s));
		}

		// 18 bodova
		TEST_METHOD(test_polyline)
		{
			vertex v{ 1,2 };
			Assert::AreEqual(1, v.x);
			Assert::AreEqual(2, v.y);

			polyline p1(4);
			p1.add({ 0,  0 });
			p1.add({ 10,  0 });
			p1.add({ 10, 10 });
			p1.add({ 0, 10 });
			Assert::AreEqual(30., p1.length());

			polyline p2(3);
			p2.add({ 1, 1 });
			p2.add({ 3, 1 });
			p2.add({ 2, 2 });
			Assert::AreEqual(2 + std::numbers::sqrt2, p2.length());

			polyline p3 = p1;
			Assert::AreEqual(30., p3.length());
		}
	};
}
