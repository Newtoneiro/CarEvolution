# CarEvolution

## Instalacja

Do zbudowania projektu potrzebujemy dwóch paczek:

1. cmake
2. build-essentials

Do zainstalowania ich należy użyć komendy ```sudo apt-get install <nazwa_paczki>```
Do uruchomienia potrzebne są 3 biblioteki. Zostaną one wymienione wraz z odpowiadającymi im paczkami na Ubuntu 22.04
LTS.

1. Box2d - ```libbox2d-dev```
2. SFML - ```libsfml-dev```
3. GTest - ```libgtest-dev```

Instalujemy je w taki sam sposób jak poprzednie paczki.
Po zainstalowaniu bibliotek należy uruchomić skrypt build.sh znajdujący się w głównym katalogu. Skrypt korzysta z cmake,
więc należy
upewnić się, że jest on zainstalowany poprawnie w wymaganej wersji.

## Uruchomienie

Po zbudowaniu programu, w katalogu ```bin``` pojawią się dwa pliki wykonywalne - ```CarEvolution```
oraz ```ExampleTests```.
W celu uruchomienia programu należy uruchomić plik wykonywalny CarEvolution, natomiast w celu uruchomienia przykładowych
testów należy uruchomić
ExampleTests.
