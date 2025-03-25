# Практична робота №3
Цей репозиторій cтворений для перегляду виконання практичної роботи №3 з дисципліни "Архітектура системного програмного забезпечення", виконане студентом Щур Р.І., групи ТВ-32.

## Завдання №1
Запустіть Docker-контейнер і поекспериментуйте з максимальним лімітом ресурсів відкритих файлів. Для цього виконайте команди у вказаному порядку:

![PrH3.1.png](PrH3.1.png)
## Виконання
![Pr3.1.png](Pr3.1.png)

Виконавши команди, видно, що при стандартних налаштуваннях Docker неможливо встановити soft ліміт, який перевищує hard ліміт; його можна змінювати лише в межах hard ліміту.

## Завдання №2
У Docker-контейнері встановіть утиліту perf(1). Поекспериментуйте з досягненням процесом встановленого ліміту.

## Виконання

## Завдання №3
Напишіть програму, що імітує кидання шестигранного кубика. Імітуйте кидки, результати записуйте у файл, для якого попередньо встановлено обмеження на його максимальний розмір (max file size). Коректно обробіть ситуацію перевищення ліміту.

## Виконання
![Pr3.3.png](Pr3.3.png)


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
