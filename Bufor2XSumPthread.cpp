#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int ile_0;

pthread_mutex_t mutex_0;

uint32_t *bufor_0 = (uint32_t*) malloc(ile_0*sizeof(int));
uint32_t *bufor_1 = (uint32_t*) malloc(ile_0*sizeof(int));

struct Blok_0 {
	uint32_t head;
	uint32_t thaly;

	double x;
	double y;
};

void*Wczytaj_0(void*argumenty) {
	Blok_0*q=(Blok_0*)argumenty;

	cout<<"Podaj ile = ";
	cin>>ile_0;
	cout<<endl;

	q->head++;

	if(q->head == ile_0)
		q->head=0;
	if(q->head == q->thaly)
		exit(-1);
	for(q->head=0; q->head<ile_0; q->head++) {
		cout<<"Wyraz ["<<q->head<<"] = ";
		cin>>bufor_0[q->head];
	}
	pthread_mutex_unlock(&mutex_0);
	cout<<endl;
	return 0;
}

void*Wczytaj_1(void*argumenty) {
	Blok_0*q=(Blok_0*)argumenty;

	cout<<"Podaj ile = ";
	cin>>ile_0;
	cout<<endl;

	q->head++;

	if(q->head == ile_0)
		q->head=0;
	if(q->head == q->thaly)
		exit(-1);
	for(q->head=0; q->head<ile_0; q->head++) {
		cout<<"Wyraz ["<<q->head<<"] = ";
		cin>>bufor_1[q->head];
	}
	pthread_mutex_unlock(&mutex_0);
	cout<<endl;
	return 0;
}

void*Suma_0(void*argumenty) {
	Blok_0*q0=(Blok_0*)argumenty;
	Blok_0*q1=(Blok_0*)argumenty;

	pthread_mutex_lock((&mutex_0));

	q0->thaly++;

	if(q0->thaly == ile_0)
		q0->thaly=0;
		
	if(q0->head == q0->thaly)
		exit(-1);
		
	q1->thaly++;
	
	if(q1->thaly == ile_0)
		q1->thaly=0;
		
	if(q1->head == q1->thaly)
		exit(-1);
		

    cout<<"WATEK_0 PO SUMOWANIU"<<endl;
	cout<<endl;
	
	for(q0->thaly=0; q0->thaly<ile_0; q0->thaly++) {
		cout<<"Wyraz ["<<q0->thaly<<"] = "<<bufor_1[q1->thaly]+bufor_0[q0->thaly]<<endl;
	}
	
	return 0;
}

int main(int argc,const char * argv[]) {
    
    pthread_t watek_0;
    
    Blok_0 obiekt_0;
    Blok_0 obiekt_1;
    
    pthread_create(&watek_0, NULL,Wczytaj_0,&obiekt_0);
	pthread_join(watek_0, NULL);
    pthread_detach(watek_0);
    
    pthread_create(&watek_0, NULL,Wczytaj_1,&obiekt_1);
	pthread_join(watek_0, NULL);
	pthread_detach(watek_0);
    
	pthread_create(&watek_0, NULL,Suma_0,&obiekt_0);
	pthread_join(watek_0, NULL);
	pthread_detach(watek_0);

	return 0;
}