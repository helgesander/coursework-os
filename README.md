# Coursework

## To fix: 

- [ ] First server (Windows)
- [x] Second server (Linux)
- [ ] Log server for first (optional)
- [x] Log server for second (optional)
- [ ] GUI client (optional)
- [ ] Some strange errors with pipes in secons server 

## Что и как работает 

Если вдруг препод спросит, где велась основная разработка, то CLion

- __get_swap_information_srv__ - здесь лежит сервер, который отсылает инфу о размере файла подкачки, работает на Windows
- __get_working_time_and_screen_size__ - здесь лежит сервер, который отсылает инфу о времени работы серверного процесса и размере экрана, работает на Linux
- __client_gui__ - там лежит сам клиент, с которого будет взаимодействие с серверами

Для каждого сервера есть свой лог сервер ([first](first/log_srv), [second](second/log_srv))

