#include <iostream>
#include <string>
using namespace std;
class Player {
private:
	int bread = 0;
	int days = 1;
	int x = 1;
	int money = 0;
public:
	Player(int bread_player, int days_player, int x_player, int money_player)
		: bread(bread_player), days(days_player), x(x_player), money(money_player)
	{

	}
	// ---------------------- ADD --------------------------
	void add_bread(int count) { bread += count; }
	void add_day(int count) { days += count; }
	void add_x(int count) { x += count; }
	void add_money(int count) { money += count; }
	// ---------------------- SET --------------------------
	void set_bread(int count) { bread = count; }
	void set_day(int count) { days = count; }
	void set_x(int count) { x = count; }
	void set_money(int count) { money = count; }
	// ---------------------- TAKE -------------------------
	void take_bread(int count) { bread -= count; }
	void take_day(int count) { days -= count; }
	void take_x(int count) { x -= count; }
	void take_money(int count) { money -= count; }
	// ---------------------- GET --------------------------
	int get_bread() { return bread; }
	int get_days() { return days; }
	int get_x() { return x; }
	int get_money() { return money; }
	// ------------------- GAMES MENU -----------------------
	void farm() {
		bread += 1;
		cout << "You have " << bread << " bread. +1 farm";
	}
	int next_day(string name) {
		money -= 150;
		if (money <= 0) {
			cout << "Sorry, but you lose game..\n";
			return 1;
		}
		else if (days == 10) {
			cout << "YOOOOOOOOOOOO YOU WIN!!!! YOU COOL!\nThank you for playing!\nLike game pls <3 andddd i say\nKOCMOC!\nyou now say: 'what?' and i say: THIS EASTER EGG!!! YOU FIND HIS!\nGoodbye " << name << "...\n";
			return 2;
		}
		else {
			days += 1;
			cout << "Yeeeee! You survive " << days << " Days! you cool!\n";
			return 0;
		}
	}
	void sell() {
		int pick_player;
		cout << "Yooo you here for sell? Yes? Okey Let's Go! pick:\n0. exit \n1. sell 1 bread\n2. sell all bread\n";
		cin >> pick_player;
		switch (pick_player) {
		case 0:
			cout << "Okey, you leave? Ok I waiting you now!\n";
			break;
		case 1:
			if (bread >= 1) {
				bread -= 1;
				money += 15;
				cout << "Yoo you have: " << money << " Money!\n";
			}
			else {
				cout << "umh.. you have 0 bread? Really? GO FARM NOOOOB\n";
			}
			break;
		case 2:
			if (bread != 0) {
				int selling_now = bread * (15 * x);
				money += selling_now;
				cout << "Yoo! You Earned: " << selling_now << " Money!\n";
				bread = 0;

			}
			else {
				cout << "Bro.. You have 0 bread? farm. farm. and farm.";
			}
			break;
		}
	}
	void shop() {
		int choose_shop;
		cout << "Hi!! I sell x! 1. +x1 - 100 money\n2. +x3 - 300 money\n";
		cin >> choose_shop;
		switch (choose_shop) {
		case 1:
			if (money >= 100) {
				money -= 100;
				x += 1;
				cout << "Yeees you have: " << x << " x money!\n";
			}
			else {
				cout << "Bro.. you not have 100 money? Really?.. bye.\n";
			}
			break;
		case 2:
			if (money >= 300) {
				money -= 300;
				x += 3;
				cout << "Yeees you have: " << x << " x money!\n";
			}
			else {
				cout << "Bro.. you not have 300 money? Really?.. bye.\n";
			}
			break;
		}
	}
};

void start_text() { cout << "To win 10 days, Pick: \n1. Farm \n2. shop\n3. sell\n4. Next day\n5. exit\n"; }

int main() {
	string name;
	cout << "Helloooo! Write your name: \n";
	cin >> name;
	cout << "Hello " << name << "! Start game? Yes! Let's GOOOOOOO!!\n";
	Player game(0, 1, 1, 0);
	int exit = 0;
	while (exit == 0) {
		int player_pick;
		start_text();
		cin >> player_pick;
		switch (player_pick) {
		case 1:
			game.farm();
			break;
		case 2:
			game.shop();
			break;
		case 3:
			game.sell();
			break;
		case 4: {
			int result_next_day = game.next_day(name);
			if (result_next_day == 1 || result_next_day == 2) {
				exit = 1;
				break;
			}
			else {
				break;
			}
			break;
		}
		case 5:
			cout << "Exit? but easter egg? no? okey i say easter egg now!: KOCMOC!!! bye " << name << "..\n";
			exit = 1;
			break;
		}
	}
	system("pause");
	return 0;

}