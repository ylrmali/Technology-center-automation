#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>


void main() {
	
	int bakiye,kategori,laptop,phones,headphones,partofpc,lpt1,hps;

	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;

	char* server = "localhost";
	char* user = "root";
	char* password = "060489a+";
	char* database = "products";

	conn = mysql_init(NULL);

	//connect to database
	if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
	}

	//asking balance
	printf("Hosgeldiniz lutfen bakiyenizi tanimlaniyiniz: ");
	scanf_s("%d", &bakiye);

	if (bakiye >= 0) {
		system("CLS");
		printf("Yeni bakiyeniz: %d TL\n\n", bakiye);

		//show products
		int kategori;
	tekrar:
		printf("-------URUNLER-------\n");
		printf("1. Laptop\n");
		printf("2. Cep Telefonu\n");
		printf("3. Kulaklik\n");
		printf("4. Bilgisayar Parcalari\n");
		printf("0. Cikis\n");
		printf("---------------------\n");
		printf("Lutfen secim yapiniz: ");
		scanf_s("%d", &kategori);

		
		switch (kategori){

			//exit
			case 0: {
				system("CLS");
				printf("Iyi gunler...");
				exit(0);
				break;
			}

			//laptops page
			case 1: {
				system("CLS");    //delect old outputs
			laptopmenu:
				printf("---------LAPTOP----------\n");
				//send SQL query
				if (mysql_query(conn, "select id,model,price from laptops")); {
					fprintf(stderr, "%s\n", mysql_error(conn));
				}
				res = mysql_use_result(conn);

				//listing laptops
				while ((row = mysql_fetch_row(res)) != NULL)
					printf("%s. %s\t%s TL\n", row[0], row[1], row[2]);
				printf("--------------------------\n");
				printf("Lutfen detaylar icin secim yapiniz ( Anamenuye donmek icin 0 ): ");
				scanf_s("%d", &laptop);

				//details of laptops
				switch (laptop){
					case 0: {
						system("CLS");
						goto tekrar;
						break;
					}

					case 1: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='1'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e laptop menusu icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						switch (lpt1){
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;

							}
							case 1: {
								if (bakiye < 15450)                      ////bu kýsýmda databaseden gelen price degerini kullanamýyorum.// database de float deger vermek denendi. + atof-strtof fonks. denendi.															
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}

								else
									printf("Iyi gunlerde kullanin :)");
							}

							break;
						}
						break;
					}

					case 2: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='2'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;
							}
							case 1: {
								if (bakiye < 18999) {                    
									system("CLS");								
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 3: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='3'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;
							}

							case 1: {
								if (bakiye < 16599) {                   ////bu kýsýmda databaseden gelen price degerini kullanamýyorum.
									system("CLS");						// database de float deger vermek denendi. + atof-strtof fonks. denendi.
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 4: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='4'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;
							}

							case 1: {
								if (bakiye < 17899) {
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 5: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='5'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;
							}

							case 1: {
								if (bakiye < 13799) {                 
									system("CLS");						
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 6: {
						system("CLS");
						//taking features
						if (mysql_query(conn, "select price,ram,cpu,screen from laptops where id='6'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);
						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Islemci: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto laptopmenu;
								break;
							}

							case 1: {
								if (bakiye < 21999) {
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					default: {
						system("CLS");
						printf("Hatali giris yaptiniz!\n");
						goto laptopmenu;
					}
				}

				break;
			}

			//phones page
			case 2: {
				system("CLS");
				
			phonesmenu:
				printf("---------CEP TELEFONLARI----------\n");
				//send SQL query
				if (mysql_query(conn, "select id,model,price from phones")) {
					fprintf(stderr, "%s\n", mysql_error(conn));
				}
				res = mysql_use_result(conn);
			
				while ((row = mysql_fetch_row(res)) != NULL)
					printf("%s. %s\t%s\n", row[0], row[1], row[2]);
				printf("----------------------\n");
				printf("Lutfen detaylar icin secim yapiniz anamenuye cikmak icin 0'a basiniz: ");
				scanf_s("%d", &phones);

				//details of phones
				switch (phones) {
					case 0:{
						system("CLS");
						goto tekrar;
						break;
					}

					case 1: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='1'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e telefon menusune donmek icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 18800)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 2: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='2'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 8999)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 3: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='3'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 10250)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 4: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='4'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");

						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 14500)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 5: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='5'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 16500)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 6: {
						system("CLS");
						//taking features of phones
						if (mysql_query(conn, "select price,ram,hafiza,ekran from phones where id='6'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Hafiza: %s\n-Ekran: %s inc\n", row[0], row[1], row[2], row[3]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e cikis yapmak icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto phonesmenu;
								break;
							}
							case 1: {
								if (bakiye < 17900)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					default :{
						system("CLS");
						printf("Hatali giris yaptiniz!\n");
						goto phonesmenu;
					}
				}



				break;
			}

			//headphones page
			case 3: {
				system("CLS");
				//send SQL query
			headphones:
				if (mysql_query(conn, "select id,model,price from headphones")) {
					fprintf(stderr, "%s\n", mysql_error(conn));
				}
				res = mysql_use_result(conn);
				printf("---------KULAKLIKLAR----------\n");
				while ((row = mysql_fetch_row(res)) != NULL)
					printf("%s. %s\t%s TL\n", row[0], row[1], row[2]);
				printf("----------------------\n");
				printf("Lutfen detaylar icin secim yapiniz anamenuye cikmak icin 0'a basiniz: ");
				scanf_s("%d", &headphones);

				switch (headphones) {
					case 0:{
						system("CLS");
						goto tekrar;
						break;
					}

					case 1:{
						system("CLS");

						//getting headphone 1
						if (mysql_query(conn, "select price,color,battery,bluetooth from headphones where id='1' ")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("---------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("Fiyat: %s TL\nRenk: %s\nBatarya: %s\nBluetooth: %s\n", row[0], row[1], row[2], row[3]);
						printf("---------------\n");
						printf("Lutfen satin almak icin 1'e kulaklik menusu icin 0'a basiniz: ");
						scanf_s("%d", &hps);
						switch (hps) {
							case 0 :{
								system("CLS");
								goto headphones;
								break;
							}

							case 1:{
								if (bakiye < 365) {
									system("CLS");
									printf("Yetersiz Bakiye!");
								}
								else {
									system("CLS");
									printf("Iyi Gunlerde Kullanin...");
								}
								break;
							}

							default: {
								system("CLS");
								printf("Hatali secim yaptiniz!\n");
								goto headphones;
								break;
							}
						}
						break;
					}

					case 2: {
						system("CLS");

						//getting headphone 2
						if (mysql_query(conn, "select price,color,battery,bluetooth from headphones where id='2' ")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("---------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("Fiyat: %s TL\nRenk: %s\nBatarya: %s\nBluetooth: %s\n", row[0], row[1], row[2], row[3]);
						printf("---------------\n");
						printf("Lutfen satin almak icin 1'e kulaklik menusu icin 0'a basiniz: ");
						scanf_s("%d", &hps);
						switch (hps){
							case 0:{
								system("CLS");
								goto headphones;
								break;
							}

							case 1:{
								if (bakiye < 2399) {
									system("CLS");
									printf("Yetersiz Bakiye!");
								}
								else {
									system("CLS");
									printf("Iyi Gunlerde Kullanin...");
								}
								break;
							}

							default: {
								system("CLS");
								printf("Hatali secim yaptiniz!\n");
								goto headphones;
								break;
							}
						}
						break;
					}

					case 3:{
						system("CLS");

						//getting headphone 3
						if (mysql_query(conn, "select price,color,battery,bluetooth from headphones where id='3' ")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("---------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("Fiyat: %s TL\nRenk: %s\nBatarya: %s\nBluetooth: %s\n", row[0], row[1], row[2], row[3]);
						printf("---------------\n");
						printf("Lutfen satin almak icin 1'e cikmak icin 0'a basiniz: ");
						scanf_s("%d", &hps);
						switch (hps) {
							case 0: {
								system("CLS");
								goto headphones;
								break;
							}

							case 1:{
								if (bakiye < 259) {
									system("CLS");
									printf("Yetersiz Bakiye!");
								}
								else {
									system("CLS");
									printf("Iyi Gunlerde Kullanin...");
								}
								break;
							}

							default: {
								system("CLS");
								printf("Hatali secim yaptiniz!\n");
								goto headphones;
								break;
							}
						}
						break;
					}

					case 4: {
						system("CLS");

						//getting headphone 4
						if (mysql_query(conn, "select price,color,battery,bluetooth from headphones where id='4' ")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("---------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("Fiyat: %s TL\nRenk: %s\nBatarya: %s\nBluetooth: %s\n", row[0], row[1], row[2], row[3]);
						printf("---------------\n");
						printf("Lutfen satin almak icin 1'e cikmak icin 0'a basiniz: ");
						scanf_s("%d", &hps);
						switch (hps) {
							case 0: {
								system("CLS");
								goto headphones;
								break;
							}

							case 1: {
								if (bakiye < 1175) {
									system("CLS");
									printf("Yetersiz Bakiye!");
								}
								else {
									system("CLS");
									printf("Iyi Gunlerde Kullanin...");
								}
								break;
							}

							default: {
								system("CLS");
								printf("Hatali secim yaptiniz!\n");
								goto headphones;
								break;
							}
						}
						break;
					}

					default: {
						system("CLS");
						printf("Hatali giris yaptiniz!\n");
						goto headphones;
						break;

					}
				}
				break;
			}

			//part of computer page
			case 4: {
				system("CLS");
				//send SQL query
			parts:
				if (mysql_query(conn, "select id,name,price from partofpc")) {
					fprintf(stderr, "%s\n", mysql_error(conn));
				}
				res = mysql_use_result(conn);

				printf("---------BILGISAYAR BILESENLERI----------\n");
				while ((row = mysql_fetch_row(res)) != NULL)
					printf("%s. %s\t\t%s TL\n", row[0], row[1], row[2]);
				printf("----------------------\n");
				printf("Lutfen detaylar icin secim yapiniz anamenu icin 0'a basiniz: ");
				scanf_s("%d", &partofpc);
				switch (partofpc){
					case 0: {
						system("CLS");
						goto tekrar;
						break;
					}

					case 1: {
						system("CLS");
						//taking features of partofpc
						if (mysql_query(conn, "select price,ram,color from partofpc where id='1'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto parts;
								break;
							}

							case 1: {
								if (bakiye < 18800)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 2: {
						system("CLS");
						//taking features of partofpc
						if (mysql_query(conn, "select price,ram,color from partofpc where id='2'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto parts;
								break;
							}

							case 1: {
								if (bakiye < 5950)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}

						}
						break;
					}

					case 3:{
						system("CLS");
						//taking features of partofpc
						if (mysql_query(conn, "select price,ram,color from partofpc where id='3'")) {
							fprintf(stderr, "%s\n", mysql_error(conn));
						}
						res = mysql_use_result(conn);

						printf("-------------------\n");
						while ((row = mysql_fetch_row(res)) != NULL)
							printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
						printf("-------------------\n");
						printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
						scanf_s("%d", &lpt1);
						system("CLS");
						switch (lpt1) {
							case 0: {
								system("CLS");
								goto parts;
								break;
							}

							case 1: {
								if (bakiye < 8150)
								{
									system("CLS");
									printf("Bakiyeniz yetersiz!");
								}
								else
									printf("Iyi gunlerde kullanin :)");
								break;
							}
						}
						break;
					}

					case 4:{
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='4'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1){
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 1680)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
						}

					case 5:{
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='5'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1) {
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 1600)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
						}

					case 6:{
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='6'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1) {
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 1235)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
						}

					case 7: {
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='7'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1) {
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 529)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
						}

					case 8: {
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='8'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1) {
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 579)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
					}

					case 9: {
							system("CLS");
							//taking features of partofpc
							if (mysql_query(conn, "select price,ram,color from partofpc where id='9'")) {
								fprintf(stderr, "%s\n", mysql_error(conn));
							}
							res = mysql_use_result(conn);

							printf("-------------------\n");
							while ((row = mysql_fetch_row(res)) != NULL)
								printf("-Fiyat: %s TL\n-Ram Bellek: %s\n-Ekran: %s\n", row[0], row[1], row[2]);
							printf("-------------------\n");
							printf("Satin almak icin 1'e bilgisayar parcalari menusu icin 0'a basiniz: ");
							scanf_s("%d", &lpt1);
							system("CLS");
							switch (lpt1) {
								case 0: {
									system("CLS");
									goto parts;
									break;
								}

								case 1: {
									if (bakiye < 560)
									{
										system("CLS");
										printf("Bakiyeniz yetersiz!");
									}
									else
										printf("Iyi gunlerde kullanin :)");
									break;
								}
							}
							break;
					}

					default: {
						system("CLS");
						printf("Hatali giris yaptiniz!\n");
						goto parts;
						break;
					}
				}

				break;
			}

			default: {
				system("CLS");
				printf("Hatali giris yaptiniz!\n");
				goto tekrar;
				
			}
		}
	}

	else {
		system("CLS");
		printf("Hatali deger girdiniz!\n");
	}
	

	








	getch();

}
