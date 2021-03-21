#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct garuda_indonesia
{
	char paspor[6];
	char nama[15];
	int nomor_kursi;
	char email[15];
	struct garuda_indonesia *next;
}
*head, *node;
struct garuda_indonesia *dummy;


void main()
{
	void pesan(int x), batal(), tampilkan();
	int pilihan;
	head = node = NULL;
	int angka = 1;
	do
	{

		printf("\n\n\t*****************************************************************");
		printf("\n\n\t                Selamat datang di Maskapai Garuda Indonesia                   ");
		printf("\n\n\t*****************************************************************");
		printf("\n\n\n\t\t Masukkan pilihan anda (1-4):");
		printf("\n\n\t\t 1. Pesan kursi penerbangan");
		printf("\n\n\t\t 2. Batal");
		printf("\n\n\t\t 3. List kursi yang sudah terisi");
		printf("\n\n\t\t 4. Exit");
		printf("\n\n\t\t      ***Terima kasih atas pilihan anda*** ");
		printf("\n\n\t\t\t ***Terbanglah bersama kami***");

        printf("\n\n\n\t\t Pilihan anda (1-4):");
		scanf("%d", &pilihan);
		fflush(stdin);
		switch (pilihan)
		{
		case 1:
			pesan(angka);
			angka++;
			break;
		case 2:
			batal();
			break;
		case 3:
			tampilkan();
			break;
		case 4:
		{
		    printf("\n\n\tTerima kasih atas reservasinya!");
				  break;
		}
		default:
			printf("\n\n\t Pilihan anda salah!");
			printf("\n\n\t Moon pilih dari no. 1-4");
		}
		getch();
	} while (pilihan != 4);
}

void detail()
{
	printf("\n\t Masukkan nomor paspor anda: ");
	gets(node->paspor); fflush(stdin);
	printf("\n\t Masukkan nama anda: ");
	gets(node->nama); fflush(stdin);
	printf("\n\t Masukkan alamat email anda: ");
	gets(node->email); fflush(stdin);

}

void detail();

void pesan(int x)
{
	node = head;
	if (head == NULL)
	{
		head = node = (struct garuda_indonesia*)malloc(sizeof(struct garuda_indonesia));
		detail();
		node->next = NULL;
		printf("\n\t Pemesanan kursi sukses!");
		printf("\n\t Nomor kursi kamu: A-%d", x);
		node->nomor_kursi = x;
		return;
	}
	else if (x > 15)
	{
		printf("\n\t\t Kursi penuh.");
		return;
	}
	else
	{
		while (node->next)
			node = node->next;
		node->next = (struct garuda_indonesia *)malloc(sizeof(struct garuda_indonesia));
		node = node->next;
		detail();
		node->next = NULL;
		printf("\n\t Pemesanan kursi sukses!");
		printf("\n\t Nomor kursi kamu : A-%d", x);
		node->nomor_kursi = x;
		return;
	}
}

void tampilkan()
{
	node = head;
	while (node)
	{
		printf("\n\n No. Paspor : %-6s", node->paspor);
		printf("\n         Nama : %-15s", node->nama);
		printf("\n      Alamat email : %-15s", node->email);
		printf("\n      No. kursi : A-%d", node->nomor_kursi);
		printf("\n\n++*=====================================================*++");
		node = node->next;
	}

}

void batal()
{
	node = head;
	char paspor[6];
	printf("\n\n Masukkan nomor paspor penumpang yang akan kamu hapus?: ");
	gets(paspor); fflush(stdin);
	if (strcmp(head->paspor, paspor) == 0)
	{
		dummy = head;
		head = head->next;
		free(dummy);
		printf(" Pemesanan telah dihapus");
		return;

	}

	while (node->next)
	{
		if (strcmp(node->next->paspor, paspor) == 0)
		{
			dummy = node->next;
			node->next = node->next->next;
			free(dummy);
			printf("Telah dihapus ");
			getch();
			return;
		}
		node = node->next;
	}
	printf("Nomor paspor salah, silakan cek lagi nomor paspor anda");

}
