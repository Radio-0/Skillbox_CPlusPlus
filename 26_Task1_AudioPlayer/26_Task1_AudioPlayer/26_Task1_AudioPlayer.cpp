/*Задание 1. Реализация имитации аудиоплеера
С помощью классов реализуйте программу имитации работы аудиоплеера.В плеере находится несколько аудиозаписей, доступных для воспроизведения.Для них вы должны cоздать отдельный класс Track.Полями этого класса должны быть : название, дата создания(здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.
Сам плеер тоже реализуйте с помощью класса.Внутри он должен содержать список доступных записей и нужные для логики работы плеера поля.
Пользователь взаимодействует с программой с помощью команд :
Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение.Воспроизведение симулируется с помощью вывода в консоль всей информации о записи.Если произведение какой - то записи уже начато, ничего не происходит.
Команда pause.Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль.Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.
Команда next переходит к следующей записи для воспроизведения.Запись при этом выбирается случайно, как будто плеер работает в режиме shuffle.
Команда stop прекращает воспроизведение текущей записи, если таковая имеется.Об этом выводится сообщение в консоль.Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.
Команда exit — выход из программы.*/

#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>

class Track {
public:
    std::string name{};
    double duration{};
    std::string dateCteate{};
};

class Player {
public:
    static const int sizeTrackList = 5;
    Track songs[sizeTrackList]{
        Track{"qwer", 5, "02.12.2022"},
        Track{"asdf", 6, "02.12.2022"},
        Track{"zxcv", 7, "02.12.2022"},
        Track{"tyui", 8, "02.12.2022"},
        Track{"ghjk", 9, "02.12.2022"},
    };
    
    int play(int numb) {
        std::string song_name;
        int numbTrack = 0;
        if (numb == (sizeTrackList + 1)) {
            std::cout << "Track list:\n";
            for (int i = 0; i < sizeTrackList; i++) {
                std::cout << songs[i].name << "\n";
            }
            std::cout << "Enter name song: ";
            std::cin >> song_name;
            for (int i = 0; i < sizeTrackList; i++) {
                if (song_name == songs[i].name) {
                    numbTrack = i;
                    std::cout << songs[i].name << " " << songs[i].duration << " " << songs[i].dateCteate << "\n";
                    break;
                }
            }
        }
        return numbTrack;
    }
    int pause(int numb, int status) {
        if (numb != (sizeTrackList + 1) && status != 1) {
            std::cout << "Track " << songs[numb].name << " on pause\n";
            status = 1;
        }            
        else if (status == 1)
            std::cout << "Track " << songs[numb].name << " is on pause\n";
        else
            std::cout << "Track is not play\n";
        return status;
    }
    int next(int numb) {
        int shuffle = (sizeTrackList + 1);
        if (numb != (sizeTrackList + 1)) {
            do {
                shuffle = rand() % sizeTrackList + 0;
            } while (shuffle == numb);
            std::cout << songs[shuffle].name << " " << songs[shuffle].duration << " " << songs[shuffle].dateCteate << "\n";
        }
        else
            std::cout << "Track is not play\n";
        return shuffle;
    }
    int stop(int numb) {
        if (numb != (sizeTrackList + 1)) {
            std::cout << "Track " << songs[numb].name << " stopped\n";
            numb = (sizeTrackList + 1);
        }
        else
            std::cout << "Track is not play\n";
        return numb;        
    }
};

int main()
{
    std::string command;
    Player* player = new Player();
    int numbTrack = (player->sizeTrackList) + 1;
    int statusTrack = 0;
    while (command != "exit") {
        std::cout << "Enter command (play, pause, next, stop, exit): ";
        std::cin >> command;
        if (command == "play") {
            numbTrack = player->play(numbTrack);
        }
        if (command == "pause") {
            statusTrack = player->pause(numbTrack, statusTrack);
        }
        if (command == "next") {
            numbTrack = player->next(numbTrack);
        }
        if (command == "stop") {
            numbTrack = player->stop(numbTrack);
        }
    }
    delete player;
    player = nullptr;
}