# Используем стабильный базовый образ Ubuntu
FROM ubuntu:22.04

# Устанавливаем зависимости и очищаем кэш
RUN apt-get update && apt-get install -y \
    qt6-base-dev \
    build-essential \
    qmake6 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Создаем рабочую директорию
WORKDIR /app

# Копируем только серверные файлы
COPY main.cpp /app/
COPY mytcpserver.cpp /app/
COPY mytcpserver.h /app/
COPY server.pro /app/
# Собираем проект
RUN qmake6 server.pro && make

# Указываем порт, который слушает сервер
EXPOSE 33333

#Запуск
#CMD ["./server"]

# Пошаговый запуск Dockerfile
# 1) Заходим в каталог с Dockerfile, и запускаем cmd из этого каталога
# 2) В командной строке вводим команду для сборки образа: docker build -t Задаем название(Допустим server):Пишем любой тег . (Пример: docker build -t server:teg.)
# 3) Запускаем контейнер командой: docker run -d -p 33333:33333 --name пишем имя контейнера(Допустим server) (Название образа):(Тег образа) (Пример: docker run -d -p 33333:33333 --name server server:teg)
# 4) Остановить работу можно командой: docker stop название контейнера (Пример: docker stop server)