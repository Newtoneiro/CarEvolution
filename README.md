# CarEvolution

## Instalacja
Do uruchomienia potrzebne są 3 biblioteki. Zostaną one wymienione wraz z odpowiadającymi im paczkami na Ubuntu 22.04 LTS.
Do zainstalowania bibliotek należy użyć komendy ```sudo apt-get install <nazwa_paczki>```

1. Box2d - ```libbox2d-dev```
2. SFML - ```libsfml-dev```
3. GTest - ```libgtest-dev```

Po zainstalowaniu bibliotek należy uruchomić skrypt build.sh znajdujący się w głównym katalogu. Skrypt korzysta z cmake, więc należy
upewnić się, że jest on zainstalowany poprawnie w wymaganej wersji.

## Uruchomienie
Po zbudowaniu programu, w katalogu ```bin``` pojawią się dwa pliki wykonywalne - ```CarEvolution``` oraz ```ExampleTests```.
W celu uruchomienia programu należy uruchomić plik wykonywalny CarEvolution, natomiast w celu uruchomienia przykładowych testów należy uruchomić
ExampleTests.
