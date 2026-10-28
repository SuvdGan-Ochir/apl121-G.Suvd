# APL121 · Бие даалт №1 — Code Quest

**Сэдэв №1: Тэгш, сондгой өдөр**

Машины дугаарын сүүлийн оронгоор өнөөдөр хотын төвөөр явж болох эсэхийг гаргана, 7 хоногийн хүснэгт хэвлэнэ, нэг гэр бүлийн 3 машинаас 7 хоногт хамгийн олон өдөр явах боломжтойг олно.

## Миний тогтоосон дүрмүүд

Багшийн тусгай дүрэм өгөөгүй тул Улаанбаатарын тээврийн хязгаарлалтыг ашигласан:

| Гараг | Хориотой сүүлийн цифр |
|-------|-----------------------|
| 1 Даваа | 1, 6 |
| 2 Мягмар | 2, 7 |
| 3 Лхагва | 3, 8 |
| 4 Пүрэв | 4, 9 |
| 5 Баасан | 5, 0 |
| 6 Бямба, 7 Ням | хориггүй |

- Цифр бүр яг нэг гаригт хориотой тул машин бүр 7 хоногт 6 өдөр явна. Иймд "хамгийн олон өдөр" хайлт тэнцсэн бүх машиныг гаргана.
- Оролтын хязгаар: цифр 0–9, гараг 1–7. Буруу бол дахин асууна.
- Хүснэгтийн мөрийн тэгшлэлт эвдрэхгүйн тулд гаралтыг латин үсгээр хэвлэсэн.
- Үндсэн томьёо: 1–5 гарагт `digit % 5 == day % 5` бол хориотой.

## Ажиллуулах

```
gcc -Wall -Wextra -o main main.c
./main
```

## Жишээ гаралт (цифр 1, 2, 3 · Даваа)

```
Onoodor (Davaa):
  Mashin 1 (tsifr 1): yavj BOLOHGUI
  Mashin 2 (tsifr 2): hotiin tuviar yavj BOLNO
  Mashin 3 (tsifr 3): hotiin tuviar yavj BOLNO

7 honogiin husnegt:
Garag     Mashin 1  Mashin 2  Mashin 3
Davaa     Horiotoi  Yavna     Yavna
Myagmar   Yavna     Horiotoi  Yavna
Lhagva    Yavna     Yavna     Horiotoi
Purev     Yavna     Yavna     Yavna
Baasan    Yavna     Yavna     Yavna
Byamba    Yavna     Yavna     Yavna
Nyam      Yavna     Yavna     Yavna

Hamgiin olon udur yavah (6 udur): Mashin 1 Mashin 2 Mashin 3
```

## Файлууд

| Файл | Агуулга |
|------|---------|
| `quest.fprg` | Flowgorithm хөтөлбөр |
| `flowchart.png` | Блок схем |
| `pseudocode.md` | Псевдокод |
| `main.c` | C хэл дээрх хэрэгжилт |
| `tests.md` | 5 тест |

## 7 элемент

1. Оролт/гаралт: `scanf`, `printf`
2. Үйлдэл ба илэрхийлэл: `%`, `&&`, `||`
3. Нөхцөл: `switch` (`dayName`), `if-else`
4. Давталт ба хүснэгт: `for` ба `%-10s`
5. Дэд алгоритм: `canDrive`, `countDays`, `dayName`, `readInt`
6. Хайлт: хамгийн олон өдөр явах машин
7. Оролтын шалгалт: `do-while` (`readInt`)

## Бичлэг

Холбоос: _энд оруулна_
