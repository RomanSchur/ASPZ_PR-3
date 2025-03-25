# Практична робота №3
Цей репозиторій cтворений для перегляду виконання практичної роботи №3 з дисципліни "Архітектура системного програмного забезпечення", виконане студентом Щур Р.І., групи ТВ-32.

## Завдання №1
Запустіть Docker-контейнер і поекспериментуйте з максимальним лімітом ресурсів відкритих файлів. Для цього виконайте команди у вказаному порядку:
![PrH3.1.png](PrH3.1.png)
## Виконання
![Pr3.1.png](Pr3.1.png)

Виконавши команди, видно, що при стандартних налаштуваннях Docker неможливо встановити soft ліміт, який перевищує hard ліміт; його можна змінювати лише в межах hard ліміту.

## Завдання №2
Що станеться, якщо передати malloc(3) від’ємний аргумент? Напишіть тестовий випадок, який обчислює кількість виділених байтів за формулою num = xa * xb. Що буде, якщо num оголошене як цілочисельна змінна зі знаком, а результат множення призведе до переповнення? Як себе поведе malloc(3)? Запустіть програму на x86_64 і x86.

## Виконання
![Pr4.2.png](Pr4.2.png)

Для виклику переповнення змінній було задано значення, яке перевищує INT_MAX. Програма на це відреагувала додаванням до мінімального значення, INT_MIN, різниці між результатом множення та INT_MAX. Саме тому результат множення вийшов від'ємним. Якщо ж передати це від'ємне значення malloc(3), то він не зможе виділити пам'ять і поверне NULL
## Завдання №3
Що станеться, якщо використати malloc(0)? Напишіть тестовий випадок, у якому malloc(3) повертає NULL або вказівник, що не є NULL, і який можна передати у free(). Відкомпілюйте та запустіть через ltrace. Поясніть поведінку програми.

## Виконання
![Pr4.3.png](Pr4.3.png)

Якщо викликати malloc(0), він може повернути NULL або вказівник. У моєму випадку malloc повернув вказівник, який можна передати у free(). Скомпілювавши та запустивши програму через ltrace, видно, як malloc повернув вказівник, як спрацювала функція free(), і те, що програма завершилась успішно.

## Завдання №4
Чи є помилки у такому коді?

![PH.png](PH.png)


## Виконання
![Pr4.4.png](Pr4.4.png)

Помилка початкового коду полягає у звільненні пам'яті в кожній ітерації циклу. Це призводить до того, що Free викликається для вже звільненої пам'яті. У виправленому коді я виніс Free за межі циклу, щоб уникнути цієї помилки.
## Завдання №5
Що станеться, якщо realloc(3) не зможе виділити пам’ять? Напишіть тестовий випадок, що демонструє цей сценарій.

## Відповідь
![Pr4.5.png](Pr4.5.png)

Для перевірки я спробував передати у realloc(3) максимальне значення size_t, в результаті realloc не вдалося змінити розмір пам'яті, і він повернув NULL.
## Завдання №6
Якщо realloc(3) викликати з NULL або розміром 0, що станеться? Напишіть тестовий випадок.

## Виконання
![Pr4.6.png](Pr4.6.png)

Результатом виклику realloc з NULL є виділення вказаного обсягу пам'яті, тобто функція спрацює як malloc. Якщо ж використати realloc з розміром 0, то вона мала б повернути NULL і звільнити попередньо виділену пам'ять, але в моєму випадку цього не сталося.
## Завдання №7
Перепишіть наступний код, використовуючи reallocarray(3):

![PH2.png](PH2.png)

Порівняйте результати виконання з використанням ltrace.
