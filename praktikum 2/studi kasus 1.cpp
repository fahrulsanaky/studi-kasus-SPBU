#include <iostream>
#include <conio.h>
using namespace std;

class Hitung {
	friend ostream& operator<<(ostream&, const Hitung&);
	friend istream& operator>>(istream&, Hitung&);
	
	public:
		hitung();
		void hitung_totalnya(){ 
		if(bensin=="pertalite"){
			total = (pertalite*liter);
		}else{
			total = (pertamax*liter);
		} 
		}
	private:
		int pertalite = 7000, pertamax = 9000;
		int liter, total;
		string nama, bensin;
};
	istream& operator>>(istream& in, Hitung& masukan) {
	cout << "Masukkan nama : ";
	in >> masukan.nama;
	cout << "jenis bensin:\npertalite\npertamax\nMasukkan jenis bensin : ";
	in >> masukan.bensin;
	cout << "berapa liter yang ingin dibeli : ";
	in >> masukan.liter;
	return in;
}
	ostream& operator<<(ostream& out, const Hitung& keluaran) {
	out << "\n\n\nstruk" << endl;
	out << "nama pelanggan    : " << keluaran.nama << endl;
	out << "jenis bensin      : " << keluaran.bensin << endl;
	out << "total liter       : " << keluaran.liter << " liter " << endl;
	out << "total pembayaran  : " << keluaran.total << endl;
	return out;
}
main() {
	Hitung X;
	cin >> X;
	X.hitung_totalnya();
	cout << X;
	getch();
	return 0;
}
