#include "StudentasTest.h";
#include "My_libs.h";


using std::cout;
using std::endl;
using std::string;
using std::vector;

Studentas::Studentas(string v, string p, float g) {
    vardas_ = v;
    pavarde_ = p;
    galutinisVid_ = g;
}
Studentas::Studentas(const Studentas& st) {
    vardas_ = st.vardas_;
    pavarde_ = st.pavarde_;
    egzaminas_ = st.egzaminas_;
    galutinisVid_ = st.galutinisVid_;
    nd_ = st.nd_;
}
Studentas& Studentas::operator=(const Studentas& st) {
    if (&st == this) return *this;
    vardas_ = st.vardas_;
    pavarde_ = st.pavarde_;
    egzaminas_ = st.egzaminas_;
    galutinisVid_ = st.galutinisVid_;
    nd_ = st.nd_;
    return *this;
}

void Studentas::setVardas(string a) { vardas_ = a; }
void Studentas::setPavarde(string b) { pavarde_ = b; }
void Studentas::setEgzaminas(int n) { egzaminas_ = n; }
void Studentas::setND(vector<float> nd) { nd_ = nd; }
void Studentas::setGalutinisVid(float g) { galutinisVid_ = g; }

float Studentas::vidurkis() {
    if (nd_.size() == 0)
        throw std::domain_error("negalima skaiciuoti vidurkio tusciam vektoriui");
    return std::accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
}
float Studentas::galBalas(const char s) {
    if (s == 'v') {
        galutinisVid_ = 0.6 * egzaminas_ + 0.4 * vidurkis();
        return galutinisVid_;
    }
    else if (s == 'm') {
        galutinisVid_ = 0.6 * egzaminas_ + 0.4 * mediana(nd_);
        return galutinisVid_;
    }

}
vector<Studentas> Studentas::padalijimas3_(vector<Studentas>& vec) {
    std::partition(vec.begin(), vec.end(), pred_);
    vector<Studentas> nabagai;
    vector<Studentas>::iterator it = std::partition_point(vec.begin(), vec.end(), pred_);
    for (it;it != vec.end();it++) {
        nabagai.push_back(*it);
    }

    vec.erase(std::partition_point(vec.begin(), vec.end(), pred_), vec.end());
    return nabagai;
}
bool Studentas::pred_(const Studentas& st) {
    return st.galutinisVid_ >= 5;

}


bool operator==(const Studentas& a, const Studentas& b) {
    return a.pavarde_ == b.pavarde_ && a.vardas_ == b.vardas_;
}
float Studentas:: mediana(vector<float> vec) {
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Klaida! Negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}
