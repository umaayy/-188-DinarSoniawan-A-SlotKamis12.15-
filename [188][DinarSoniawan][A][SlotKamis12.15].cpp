//KODE SOAL A
#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct Kelas{
	string lokasi, fasilitas;
	int kapasitas; 
};

struct Jadwal{
	string matkul, dosen, waktu, kebutuhanRuang;
};

void tambahKelas(){
	int n;
	cout<<"Ingin menambahkan berapa kelas : ";
	cin>>n;
	cin.ignore();
	Kelas* kelas = new Kelas[n]; 
	for(int i = 0; i < n; i++){
		cout<<"Masukan kelas ke-"<<i+1<<endl;
		cout<<"Masukan kapasitas : ";
		cin>>kelas[i].kapasitas;
		cin.ignore();
		cout<<"Masuka lokasi (Latai/gedung) : ";
		getline(cin, kelas[i].lokasi);
		cout<<"Masukan fasilitas : ";
		getline(cin, kelas[i].fasilitas);
	}
	ofstream file("kelas.txt", ios::app);
	if(file.is_open()){
		for(int i = 0; i< n;i++){
		file<<kelas[i].kapasitas<<"|"<<kelas[i].lokasi<<"|"<<kelas[i].fasilitas<<endl;
		}	
		file.close();
		cout<<"berhasil inpust data !!"<<endl;
	}else{
		cout<<"gagal cuy"<<endl;
	}
	delete[] kelas;
	
}


void gantiJadwal(){
	int n;
	cout<<"Ingin ada berapa matkul dala satu hari ?  : ";
	cin>>n;
	cin.ignore();
	Jadwal* jadwal = new Jadwal[n]; 
	for(int i = 0; i < n; i++){
		cout<<"Masukan matkul ke-"<<i+1<<endl;
		cout<<"Masukan matkul : ";
		getline(cin, jadwal[i].matkul);
		cout<<"Masuka nama dosen : ";
		getline(cin, jadwal[i].dosen);
		cout<<"Masukan Waktu : ";
		getline(cin, jadwal[i].waktu);
		cout<<"Masukan Kebutuhan ruang : ";
		getline(cin, jadwal[i].kebutuhanRuang);
	}
	ofstream file("jadwal.txt", ios::app);
	if(file.is_open()){
		for(int i = 0; i< n;i++){
		file<<jadwal[i].matkul<<"|"<<jadwal[i].dosen<<"|"<<jadwal[i].waktu<<"|"<<jadwal[i].kebutuhanRuang<<endl;
		}	
		file.close();
		cout<<"berhasil inpust data !!"<<endl;
	}else{
		cout<<"gagal cuy"<<endl;
	}
	delete[] jadwal;
	
}

void lihatJadwal(){
	cout<<"===================================\n";
	cout<<"					Jadwal				\n";
	cout<<"===================================\n";
	cout<<"Nama Dosen	: wahyu pujiaono\n";	
	cout<<"Nama Matkul	: Alpro\n";	
	cout<<"Waktu		: 12-15 - 15:00\n";	
	cout<<"Kebutuhan	: Matkul harian\n";	

}

void unduhJadwal(){
	ifstream file("jadwal.txt");
	string baris;
	size_t pos = 0;
	string data[4];
	if(file.is_open()){
		while(baris, file){	
		}
	system("START /MIN NOTEPAD jawal.txt");
	}
	

}

void menuAdmin(){
	int pilihan;
	cout<<"Anda masuk sebagai ADMIN : "<<endl;
	cout<<"1. tambahkan ruang kelas"<<endl;
	cout<<"2. hapus ruang kelas"<<endl;
	cout<<"3. Ganti jadwal kelas "<<endl;
	cout<<"4. Hapus jadwal kelas"<<endl;
	cout<<"masukan salah satu : ";
	cin>>pilihan;
	if(pilihan == 1){
		tambahKelas();
	}else if(pilihan == 2){
		cout<<"fitur ini belum!!"<<endl;
		cout<<"yang sudah fitur 1 dan 3"<<endl;
	}else if(pilihan == 3){
		gantiJadwal();
	}else if(pilihan == 4){
		cout<<"fitur ini belum!!"<<endl;
		cout<<"yang sudah fitur 1 dan 3"<<endl;
	}
}

void menuMhs(){
	int pilihan;
	cout<<"Anda masuk sebagai MAHASISWA : "<<endl;
	cout<<"1. lihat jadwal"<<endl;
	cout<<"2. Unduh jadwal"<<endl;
	cout<<"masukan salah satu : ";
	cin>>pilihan;
	if(pilihan == 1){
		lihatJadwal()
;	}else if(pilihan == 2){
	unduhJadwal();
	}
}

void utama(){
	string username;
	int password;
	cout<<"anda harus login terlebih dahulu : "<<endl;
	cout<<"Masukan Username : ";
	cin>>username;
	cout<<"masukan Password : ";
	cin>>password;
	cin.ignore();
	if(username == "admin" && password == 1994){
		menuAdmin();
	}else if(username == "mhs" && password == 1994){
		menuMhs();
	}
	
}




int main(){
    utama();
}
