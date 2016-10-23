// Inheritance5_MagicSpells.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower(){
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower(){
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower(){
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower(){
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	/* Enter your code here */
	string name = spell->revealScrollName();
	if (name == "") {
		Fireball* f = dynamic_cast<Fireball*>(spell);
		if (f != NULL){
			f->revealFirepower();
			return;
		}
		delete[] f;

		Frostbite* fr = dynamic_cast<Frostbite*>(spell);
		if (fr != NULL){
			fr->revealFrostpower();
			return;
		}
		delete[] fr;

		Thunderstorm* th = dynamic_cast<Thunderstorm*>(spell);
		if (th != NULL){
			th->revealThunderpower();
			return;
		}
		delete[] th;

		Waterbolt* wa = dynamic_cast<Waterbolt*>(spell);
		if (wa != NULL){
			wa->revealWaterpower();
			return;
		}
		delete[] wa;
	} 
	else {
		string jo = SpellJournal::read();
		vector<vector<int>> C;
		int m = jo.size();
		int n = name.size();
		C.resize(m+1);
		for (int i = 0; i < m+1; i++){
			C[i].resize(n+1);
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (name[j-1] == jo[i-1]){
					C[i][j] = C[i-1][j-1] + 1;
				}
				else {
					C[i][j] = ((C[i][j-1] > C[i-1][j]) ? C[i][j-1] : C[i-1][j]);
				}
			}
		}
		cout << C[m][n] << endl;
	}
}

class Wizard {
public:
	Spell *cast() {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
	system("pause");
	return 0;
}