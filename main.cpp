#include <iostream>
#include <iomanip>
#include <conio.h>
#define ADET 16
using namespace::std;
string urunler[ADET];
float fiyatlar[ADET];
int sepet[ADET] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
int sepettekiUrun=0;
void CizgiCiz(int genislik){
	cout<<" ";
	for(int i=0;i<genislik-1;i++){
		cout<<"_";
	}
}
void BoslukCiz(int genislik){
	cout<<"|";
	for(int j=0;j<genislik;j++){
		cout<<" ";
	}
	cout<<"|"<<endl;
}

void UrunleriYaz() {
	int genislik = 80, yukseklik = 9, satirurun = ADET / 4, sutunurun = ADET / 4;int sira=0;
	cout<<" ";
	for(int i=0;i<genislik;i++){
		if(i==50){i+=20;
			cout<<left<<setw(16)<<"Sepetteki Urun [ "<<setw(2)<<sepettekiUrun<<setw(2)<<"]";
		}
		else cout<<"_";
	}
	cout<<endl;
	for(int i=0;i<yukseklik;i++){
		if(i>2&&i<7){
			cout<<"|";
			for(int j=0;j<ADET;j+=4){
				cout<<left<<setw(5)<<" "<<setw(2)<<j+sira+1<<setw(1)<<"."<<setw(genislik/sutunurun-8)<<urunler[j+sira];
			}
			sira++;
			cout<<"|"<<endl;
		}
		else{
			BoslukCiz(genislik);
		}
	}
	cout<<"|";
	CizgiCiz(genislik);
	cout<<"|"<<endl;
}
void SepetYaz(){
	CizgiCiz(80);
	cout<<endl;
	BoslukCiz(80);
	cout<<right<<"|"<<setw(45)<<"Sepetteki Urunler"<<setw(36)<<"|"<<endl;
	BoslukCiz(80);
	cout<<"|";
	CizgiCiz(80); 
	cout<<"|"<<endl<<endl<<endl;
	float toplam = 0;
	for(int i=0;i<ADET;i++){
		if(sepet[i]!=-1){
			cout<<left<<setw(5)<<" "<<setw(15)<<urunler[i]<<setw(2)<<"x"<<setw(3)<<sepet[i]<<right<<setw(20)<<fiyatlar[i]<<"TL"<<setw(1)<<" x"<<setw(3)
			<<sepet[i]<<setw(1)<<" ="<<setw(5)<<(sepet[i]*fiyatlar[i])<<"TL"<<endl;
			toplam = toplam + (sepet[i]*fiyatlar[i]);
		}
	}
	cout<<endl<<endl;
	CizgiCiz(80);
	cout<<endl<<endl;
	cout<<right<<setw(10)<<"TOPLAM"<<right<<setw(48)<<toplam<<"TL"<<endl<<endl;
	cout<<"Cikmak icin herhangi bir tusa basin"<<endl;
}
int main(int argc, char** argv) {
	urunler[0] = "Domates";urunler[1] = "Kabak";urunler[2] = "Havuç";urunler[3] = "Patlican";
	urunler[4] = "Iceberg";urunler[5] = "Salatalik";urunler[6] = "Marul";urunler[7] = "Lahana";
	urunler[8] = "Elma";urunler[9] = "Portakal";urunler[10] = "Mandalina";urunler[11] = "Armut";
	urunler[12] = "Cips";urunler[13] = "Kola";urunler[14] = "IceTea";urunler[15] = "Kek";
	fiyatlar[0] = 1.5;fiyatlar[1] = 2.5;fiyatlar[2] = 5.0;fiyatlar[3] = 1.0;fiyatlar[4] = 2.0;fiyatlar[5] = 2.0;
	fiyatlar[6] = 10;fiyatlar[7] = 12;fiyatlar[8] = 5;fiyatlar[9] = 5.5;fiyatlar[10] = 0.5;
	fiyatlar[11] = 1;fiyatlar[12] = 2;fiyatlar[13] = 3;fiyatlar[14] = 4.5;fiyatlar[15] = 5;
	int malzemeno,adet;
	while(true){
		system("cls");
		UrunleriYaz();
		do{
			cout<<endl<<"Malzeme Secin:";
			cin>>malzemeno;
			malzemeno--;
			if(cin.fail()||(malzemeno<0||malzemeno>=ADET)){
				system("cls");
				UrunleriYaz();
				cout<<endl<<"Hatali Bir Tuslama Yaptiniz!"<<endl<<endl;
				cin.clear();
				cin.ignore(256,'\n');
			}
		}while(cin.fail()||(malzemeno<0||malzemeno>=ADET));
		do{
			cout<<urunler[malzemeno]<<"(Adet "<<fiyatlar[malzemeno]<<" TL)"<<" Adedi Girin:";
			cin>>adet;
			if(cin.fail()){
				cout<<endl<<"Hatali Bir Islem Yaptiniz!"<<endl<<endl;
				cin.clear();
				cin.ignore(256,'\n');
			}
			else{
				break;
			}
		}while(true);
		if(sepet[malzemeno]==-1){
			sepet[malzemeno]=adet;
			cout<<"Urun Sepete Eklendi"<<endl;
			sepettekiUrun++;
		}
		else{
			sepet[malzemeno]+=adet;
			cout<<"Urun Zaten Mevcuttu Miktar bilgisi Guncellendi"<<endl;
		}
		char c;
		do{
			cout<<"Baska Urun Eklemek Ister misiniz (y/n)?";
			cin>>c;
			if(c!='y'&&c!='Y'&&c!='n'&&c!='N'){
				system("cls");
				UrunleriYaz();
				cout<<endl<<"Hatali bir tuslama yaptiniz!"<<endl<<endl;
			}
		}while(c!='y'&&c!='Y'&&c!='n'&&c!='N');
		if(c=='n'||c=='N')break;
	}
	SepetYaz();
	getch();
	return 0;
}

