/*Задание 1. Реализация имитации аудиоплеера
С помощью классов реализуйте программу имитации работы аудиоплеера.В плеере находится несколько аудиозаписей, доступных для воспроизведения.Для них вы должны cоздать отдельный класс Track.Полями этого класса должны быть : название, дата создания(здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.
Сам плеер тоже реализуйте с помощью класса.Внутри он должен содержать список доступных записей и нужные для логики работы плеера поля.
Пользователь взаимодействует с программой с помощью команд :
Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение.Воспроизведение симулируется с помощью вывода в консоль всей информации о записи.Если произведение какой - то записи уже начато, ничего не происходит.
Команда pause.Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль.Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.
Команда next переходит к следующей записи для воспроизведения.Запись при этом выбирается случайно, как будто плеер работает в режиме shuffle.
Команда stop прекращает воспроизведение текущей записи, если таковая имеется.Об этом выводится сообщение в консоль.Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.
Команда exit — выход из программы.*/

#include <iostream>
#include <string>
#include <vector>

class Player;

enum Status
{
    PLAY,
    PAUSE,
    STOP
};

class Track {
    std::string name{};
    double duration{};
    std::string dateCteate{};
public:
    Track(std::string name, double duration, std::string dateCteate) : name(name), duration(duration), dateCteate(dateCteate) {}
    std::string getName(){ 
        return name;
    }
    double getDuration(){
        return duration;
    }
    std::string getDate(){
        return dateCteate;
    }
};

class Player {
    std::vector<Track> songs{
        Track("qwer", 5, "20.02.2022"),
        Track("asdf", 6, "20.02.2022"),
        Track("zxcv", 7, "20.02.2022"),
        Track("tyui", 8, "20.02.2022"),
        Track("ghjk", 9, "20.02.2022")
    };
    Status statusTrack = STOP;
    int numbTrack = 0;
public:
    void setNumb(int value) {
        numbTrack = value;
    }
    void play() {
        std::string song_name;
        if (statusTrack == STOP) {
            std::cout << "Track list:\n";
            for (int i = 0; i < songs.size(); i++) {
                std::cout << songs[i].getName() << "\n";
            }
            std::cout << "Enter name song: ";
            std::cin >> song_name;
            for (int i = 0; i < songs.size(); i++) {
                if (song_name == songs[i].getName()) {
                    setNumb(i);
                    statusTrack = PLAY;
                    std::cout << songs[i].getName() << " " << songs[i].getDuration() << " " << songs[i].getDate() << "\n";
                    break;
                }
            }
        }
    }
    void pause() {
        if (statusTrack != PAUSE && statusTrack != STOP) {
            std::cout << "Track " << songs[numbTrack].getName() << " on pause\n";
            statusTrack = PAUSE;
        }            
        else if (statusTrack == PAUSE)
            std::cout << "Track " << songs[numbTrack].getName() << " is on pause\n";
        else
            std::cout << "Track is not play\n";
    }
    void next() {
        int shuffle;
        if (statusTrack != STOP) {
            do {
                shuffle = rand() % songs.size() + 0;
            } while (shuffle == numbTrack);
            setNumb(shuffle);
            std::cout << songs[shuffle].getName() << " " << songs[shuffle].getDuration() << " " << songs[shuffle].getDate() << "\n";
        }
        else
            std::cout << "Track is not play\n";
    }
    void stop() {
        if (statusTrack != STOP) {
            std::cout << "Track " << songs[numbTrack].getName() << " stopped\n";
            statusTrack = STOP;
        }
        else
            std::cout << "Track is not play\n";
    }
};

int main()
{
    std::string command;
    Player* player = new Player();
    while (command != "exit") {
        std::cout << "Enter command (play, pause, next, stop, exit): ";
        std::cin >> command;
        if (command == "play") {
            player->play();
        }
        else if (command == "pause") {
            player->pause();
        }
        else if (command == "next") {
            player->next();
        }
        else if (command == "stop") {
            player->stop();
        }
    }
    delete player;
    player = nullptr;
}