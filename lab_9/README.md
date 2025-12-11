# Отчёт по лабораторной работе №9
1. Создаю папку progrraming, затем использую  git status, чтобы узнать, на какой ветке я нахожусь
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 100332-1.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 100519-1.png>)
2. git log говорит, что коммитов ещё не было
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 100545.png>)
3. (4.5.6) Создаю файл sort.c с помощью touch и вставляю в него bubble сортировку. git status говорит, что я на ветке master
![alt text](</lab_9/screenshots/image.png>)
После добавления файла в область staged git status говорит, что файл sort.c был добавлен. Теперь git знает о нём
![alt text](</lab_9/screenshots/image-1.png>)
7. Делаю коммит с сообщением
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 103306.png>)
8. git status показывает, что нет новых или изменённых файлов
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 103621.png>)
9.10.11.12. Добавила комментарий #hello git 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 103705.png>)
Сделала git add. git status показывает, что файл изменён
13. Добавила строчку #hello world и сделала коммит. Так как второе изменение не было добавлено в staged заккомитилось только первое изменение
![alt text](</lab_9/screenshots/image-2.png>)
15. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-21 104548.png>)
16. Первый пуш
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 151756-1.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 152721-1.png>)

# Ветки

1. создаю новую ветку mybranch
2. С помощью git branch проверяю, что ветка создана 
3. Переключаюсь на неё с помощью git switch.
4. git status говорит, на какой я ветке. При переключении с одной ветки на другую вывод git status меняется
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 120800.png>)
5. git status показывает, что я на ветке mybranch
6. Создаю file1.txt со своим именем
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 121101.png>)
7. Добавила файл и сделала коммит с комментарием 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 121349.png>)
8. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 121510.png>)
9. Переключаюсь на master
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 121637.png>)
10. В git log нет моего последнего коммита из ветки mybranch
11. Создаю file2.txt и делаю коммит
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 121922.png>)
12. Ветка указывает на новый коммит
13. 14. Переключаюсь на mybranch и вижу, что file2.txt нет
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-25 122212.png>)
15. 16. Добавляю текстовый документ со скриншотами в ветку mybranch, делаю коммит и пушу
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 151338.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 152721.png>)

# На оценку 4

1. Переключаюсь с master на mybranch, в которой находится файл sort.c
2. Добавляю в функцию main() массив и вызываю функцию сортировки для него
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 095528.png>)
3. git diff показывает, что было добавлено
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 153830.png>)
4. git diff --staged пустой
5. Добавляю sort.c в staged
6. Теперь git diff пустой
7.  git diff --staged показывает изменения в файле
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 154923.png>)
8. Удаляю из массива 0
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 154717.png>)
9. (10) 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 095915.png>)
11. Так как файл не добавлен в staged после изменений git diff показывает изменения, а  git diff --staged пустой
12. Запускаю git status. Вижу, что  sort.c присутствует дважды в выводе
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-26 155033.png>)
13. Запускаю git restore --staged sort.c, чтобы отменить индексацию изменения
14. Теперь в выводе sort.c присутствует один раз
15. Индексирую изменения и делаю коммит 
16. Смотрю журнал с помощью git log
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-27 105935-1.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 101455.png>)
17. В файле sort.c был добавлен в main() printf(“hello git\n”)
18. Его содержимое:
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 101605.png>)
19. 20. git status гворит, что файл sort.c был изменён и не добавлен в staged
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 101703.png>)
21. Можно увидеть, что изменения исчезли
22. git status больше не видит изменений в файле 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 101723.png>)
23. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 101750.png>)

# Ветки и ff-merge

1. Был создан greeting.txt, проиндексирован с помощью git add и закоммичен с сообщением “Add file greeting.txt”
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 102136.png>)
2. Добавлено hello
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 102221.png>)
3.(4. 5. 6. 7. 8) Создала ветка с именем feature/uppercase, переключилась на неё с помощью git switch. git status говорит, что я на ветке feature/uppercase. Отредактировала greeting.txt, чтобы он содержал приветствие в верхнем 
регистре (HELLO). Файл добавлен и закоммичен
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 102516.png>)
9. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 102636.png>)
10. Переключилась на mybranch.
11. в этой ветке с помощью команды cat вывела терминале содержимое файла
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 102856.png>)
12. Ветки содержат один и тот же файл
13. С помощью git merge объединяю ветки
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 103202.png>)
14. Удаляю ветку feature/uppercase с помощью опции -d команды git branch. Переключаюсь на ветку master
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 103555.png>)
15. 16. Сделала коммит, чтобы смержить ветки
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 103847.png>)
17. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 103901.png>)
18. Запушила на удалённый репозиториий

# На оценку 5. Исправление merge conflict’ов

1. (2. 3) Создала ветку branch1 и записала с помощью  echo "This is a relevant fact" > file.txt сторчку в file.txt. Закоммиьела изменение
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104244.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104311.png>)
4.(5) Переключилась на master и выполнила команду 
echo "This is an indispensable truth!" > file.txt 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104549.png>)
6. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104751.png>)
7. (8) Смержила branch1 в maaster. Можно увидеть, что произошёл merge conflict из-за разного содержимого одной строчки в одном и том же файле
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104900.png>)
9. Исправляю конфликт в VSCode
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 104952.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 105148.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 105205.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 105943.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 110105.png>)
10. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 110141.png>)
11. Запушила на удалённый репо
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 110201.png>)

# Чиню Merge конфликты для сортировки MergeSort на python

1. (2. 3. 4. 5)  Проверяю, на какой ветке я нахожусь. Создаю файл mergesort.py с содержимым base.py. Добавляю в staged, коммичу. Создаю новую ветку Mergesort-Impl и переключаюсь на нее. Содержимое файла mergesort.py заменяю на код из righty.py. Коммичу изменения.
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111223.png>)
6. (7. 8) Переключаемся на master и меняю все содержимое mergesort.py на lefty.py
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111235.png>)
9. Вывод git branch
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111306.png>)
10. Пытаюсь смержить ветки и получаю мерже конфликт. Решаю его принятием изменений
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111401.png>)
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111559.png>)
11. Коммичу с сообщением "мерж конфликт решён"
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-28 111809.png>)
12. 
![alt text](</lab_9/screenshots/Снимок экрана 2025-11-29 153550.png>)