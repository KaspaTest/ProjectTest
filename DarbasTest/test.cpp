#include "pch.h"
#include "StudentasTest.h"

TEST(Testavimas, GalutinisBalas) {
	Studentas st;
	vector<float> nd{ 1, 7, 10 };
	st.setEgzaminas(10);
	st.setND(nd);
	
	EXPECT_FLOAT_EQ(8.8, st.galBalas('m'));
	EXPECT_FLOAT_EQ(8.4, st.galBalas('v'));

}



TEST(Testavimas, Padalijimas) {
	Studentas st1("Vardas1", "Pavarde1", 4);
	Studentas st2("Vardas2", "Pavarde2", 7);
	Studentas st3("Vardas3", "Pavarde3", 3);
	Studentas st4("Vardas4", "Pavarde4", 2);
	Studentas st5("Vardas5", "Pavarde5", 10);
	vector<Studentas> vec;
	vec.push_back(st1);
	vec.push_back(st2);
	vec.push_back(st3);
	vec.push_back(st4);
	vec.push_back(st5);

	vector<Studentas> nabagai = Studentas::padalijimas3_(vec);

	EXPECT_TRUE(vec.size() == 2);
	EXPECT_TRUE(nabagai.size() == 3);
}

TEST(Testavimas, Operatorius) {
	Studentas st1("Vardas1", "Pavarde1", 10);
	Studentas st2("Vardas3", "Pavarde1", 10);

	EXPECT_FALSE(st1 == st2);

}
