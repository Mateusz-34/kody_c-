#include <iostream>
using namespace std;

class Car {
public:
    string marka, model, kolor;
    int rok_produkcji;

    Car(const string marka, const string model, const string kolor, int rok_produkcji) {
        this->marka = marka;
        this->model = model;
        this->kolor = kolor;
        this->rok_produkcji = rok_produkcji;
    }

    void dodaj_samochod() {
        cout << "Dodano samochód: " << marka << " " << model << ", kolor: " << kolor << ", rok produkcji: " << rok_produkcji << endl;
    }

    void pokaz_samochod() {
        cout << "Samochód: " << marka << " " << model << ", kolor: " << kolor << ", rok produkcji: " << rok_produkcji << endl;
    }

    virtual void jedz(int km) = 0;

protected:
    int vin;

    friend void dodaj_vin(Car& car, int vin);
    friend void pokaz_vin(const Car& car);

    class FuelCar {
    public:
        int pojemnosc_baku, stan_baku;
        double spalanie;

        void pokaz_stan_baku() {
            cout << "Stan baku: " << stan_baku << " litrów" << endl;
        }

        void zatankuj() {
            stan_baku = pojemnosc_baku;
            cout << "Benzyna zatankowana. Stan baku: " << stan_baku << " litrów" << endl;
        }
    };

    class ElectricCar {
    public:
        int poziom_baterii;
        int poziom_zuzycia_baterii;

        void laduj_baterie() {
            poziom_baterii = 100;
            cout << "Bateria naładowana. Poziom baterii: " << poziom_baterii << "%" << endl;
        }

        void pokaz_poziom_naladowania_baterii() {
            cout << "Poziom naładowania baterii: " << poziom_baterii << "%" << endl;
        }
    };
};

void dodaj_vin(Car& car, int vin) {
    car.vin = vin;
}

void pokaz_vin(const Car& car) {
    cout << "VIN samochodu: " << car.vin << endl;
}

class FuelCar1 : public Car {
public:
    FuelCar fuel;

    FuelCar1(const string& marka, const string& model, const string& kolor, int rok_produkcji, int pojemnosc_baku, double spalanie)
        : Car(marka, model, kolor, rok_produkcji) {
        fuel.pojemnosc_baku = pojemnosc_baku;
        fuel.spalanie = spalanie;
        fuel.stan_baku = 0;
    }

    void jedz(int km) override {
        int potrzebne_paliwo = (km * fuel.spalanie) / 100;
        if (fuel.stan_baku >= potrzebne_paliwo) {
            fuel.stan_baku -= potrzebne_paliwo;
            cout << "Samochód przejechał " << km << " km. Pozostały stan baku: " << fuel.stan_baku << " litrów \n" << endl;
        } else {
            cout << "Za mało paliwa na przejechanie " << km << " km. Zatankuj!" << endl;
        }
    }
};

class ElectricCar1 : public Car {
public:
    ElectricCar battery;

    ElectricCar1(const string& marka, const string& model, const string& kolor, int rok_produkcji)
        : Car(marka, model, kolor, rok_produkcji) {
        battery.poziom_baterii = 0;
        battery.poziom_zuzycia_baterii = 1;
    }

    void jedz(int km) override {
        int potrzebna_energia = km * battery.poziom_zuzycia_baterii;
        if (battery.poziom_baterii >= potrzebna_energia) {
            battery.poziom_baterii -= potrzebna_energia;
            cout << "Samochód przejechał " << km << " km. Pozostały poziom baterii: " << battery.poziom_baterii << "%" << endl;
        } else {
            cout << "Za mało energii na przejechanie " << km << " km. Naładuj baterię!" << endl;
        }
    }

    void laduj_baterie() {
        battery.laduj_baterie();
    }

    void pokaz_poziom_naladowania_baterii() {
        battery.pokaz_poziom_naladowania_baterii();
    }
};

int main() {
    FuelCar1 fuel("Ford", "Focus", "niebieski", 2018, 50, 6.5);

    fuel.dodaj_samochod();
    fuel.pokaz_samochod();
    dodaj_vin(fuel, 123456);
    pokaz_vin(fuel);
    fuel.fuel.zatankuj();
    fuel.jedz(100);

    ElectricCar1 electric("Tesla", "Model S", "czerwony", 2020);
    
    electric.dodaj_samochod();
    electric.pokaz_samochod();
    dodaj_vin(electric, 654321);
    pokaz_vin(electric);
    electric.laduj_baterie();
    electric.jedz(100);

    return 0;
}
