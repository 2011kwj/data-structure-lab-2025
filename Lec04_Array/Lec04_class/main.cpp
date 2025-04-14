//#include "Car.h"
//#include "SportsCar.h"
#include "Music.h"

int main()
{
	MusicStreamingService my_service("spotify");
	my_service.addMusic("PolaroidLove", "ENHYPEN", "DIMENSION", 2022);
	my_service.addMusic("Ditto", "NewJeans", "ALBUM", 2023);
	my_service.addMusic("CAKE", "ITZY", "ALBUM", 2023);
	my_service.addMusic("Wiplash", "AESPA", "ALBUM", 2024);
	my_service.addMusic("Attention", "NewJeans", "ALBUM", 2022);

	// add by user
	// music 객체 선언  ->>  사용자 입력받기 (cin 사용)
	//입력 받은값을 선언한 music객체 멤버변수에 하나식 채우기
	// 마지막으로 music 객체 my_service의 music_list에 push_back()

	// search misic by title
	string music_title;
	cout << " Enter the Music Title: ";
	cin >> music_title;
	Music* result = my_service.serchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: " <<result->getTitle() << "by " << result->getArtist() << endl;
	}
	else {
		cout << "not found" << endl;
	}


	//search music by Artist
	string artist_name;
	cout << "Enter the Artist Name : ";
	cin >> artist_name;
	vector<Music*>artist_result = my_service.searchByArtist(artist.name);
	if (artist_result.size() > 0) {
		cout << "Found" << artist_result.size() << "songs by" << artist_name << ": " << endi;
		for (int i = 0; i < artist_result.size() : i++); {
			cout << artust_result[i]->getTitle() << endl;
		}
	else {
		cout << "not found" << endl;
	}
	}
}

