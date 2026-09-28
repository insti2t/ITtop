<!-- suppliers (id, city); - поставщик
parts (id, name); - детали
shipments (id, supplier_id, part_id); - поставка (заказ)

Формулы вставляются через знак $, например $a\ +\ b\ =\ c$
$$ - для выравнивания по центру.

верхний индекс: a^{b+c}  ab+c
нижний индекс: a_{b+c} ab+c
логическое и: \land
логическое или: \lor -->


| Символ | Название (англ.) | Операция (рус.) | Приоритет | TeX |
| :---: | :--- | :--- | :---: | :--- |
| `\` | MINUS | Разность | 1 | `\backslash` |
| `∪` | UNION | Объединение | 1 | `\cup` |
| `÷` | DIVIDE BY | Деление | 2 | `\div` |
| `∩` | INTERSECT | Пересечение | 2 | `\cap` |
| `⋈` | JOIN | Соединение | 2 | `\bowtie` |
| `×` | TIMES | Декартово произведение | 2 | `\times` |
| `π` | PROJECT | Проекция (projection) | 3 | `\pi` |
| `σ` | WHERE | Выборка (selection) | 3 | `\sigma` |
| `ρ` | RENAME | Переименование | 4 | `\rho` |

## задание 1

|  Метод (язык) | Выражение |
| :--- | :--- |
| **Реляционная алгебра** (Символы) | \(\pi_{\text{PNAME}} ( \sigma_{\text{PID} > 20} (\text{P}) \bowtie \text{SP} )\) |
| **Реляционная алгебра** (TeX) | `\pi_{\text{PNAME}} ( \sigma_{\text{PID} > 20} (\text{P}) \bowtie \text{SP} )` |
| **Реляционное исчисление кортежей** | \(\{ t \cdot \text{PNAME} \mid \exists p \in \text{P} \, \exists sp \in \text{SP} \, (p.\text{PID} = sp.\text{PID} \land p.\text{PID} > 20 \land t.\text{PNAME} = p.\text{PNAME}) \}\) |
| **SQL** | `SELECT DISTINCT P.PNAME FROM P JOIN SP ON P.PID = SP.PID WHERE P.PID > 20;` |

## задание 2

| Метод(язык) | Выражение |
| :--- | :--- |
| **Реляционная алгебра** (Символы) | \(\pi_{\text{J.*}} ( \text{J} \bowtie \text{SPJ} \bowtie \sigma_{\text{CITY} = \text{'London'}} (\text{S}) )\) |
| **Реляционная алгебра** (TeX) | `\pi_{\text{J.*}} ( \text{J} \bowtie \text{SPJ} \bowtie \sigma_{\text{CITY} = \text{'London'}} (\text{S}) )` |
| **Реляционное исчисление кортежей** | \(\{ j \mid j \in \text{J} \land \exists spj \in \text{SPJ} \, \exists s \in \text{S} \, (j.\text{JID} = spj.\text{JID} \land spj.\text{SID} = s.\text{SID} \land s.\text{CITY} = \text{'London'}) \}\) |
| **SQL** | `SELECT DISTINCT J.* FROM J JOIN SPJ ON J.JID = SPJ.JID JOIN S ON SPJ.SID = S.SID WHERE S.CITY = 'London';` |

## задание 3

| Метод(язык) | Выражение |
| :--- | :--- |
| **Реляционная алгебра** (Символы) | \(\pi_{\text{J.*}} ( \text{J} \bowtie \text{SPJ} \bowtie \sigma_{\text{CITY} = \text{'London'}} (\text{S}) \bowtie \sigma_{\text{PNAME} = \text{'Monitor'}} (\text{P}) )\) |
| **Реляционная алгебра** (TeX) | `\pi_{\text{J.*}} ( \text{J} \bowtie \text{SPJ} \bowtie \sigma_{\text{CITY} = \text{'London'}} (\text{S}) \bowtie \sigma_{\text{PNAME} = \text{'Monitor'}} (\text{P}) )` |
| **Реляционное исчисление кортежей** | \(\{ j \mid j \in \text{J} \land \exists spj \in \text{SPJ} \, \exists s \in \text{S} \, \exists p \in \text{P} \, (j.\text{JID} = spj.\text{JID} \land spj.\text{SID} = s.\text{SID} \land spj.\text{PID} = p.\text{PID} \land s.\text{CITY} = \text{'London'} \land p.\text{PNAME} = \text{'Monitor'}) \}\) |
| **SQL** | `SELECT DISTINCT J.* FROM J JOIN SPJ ON J.JID = SPJ.JID JOIN S ON SPJ.SID = S.SID JOIN P ON SPJ.PID = P.PID WHERE S.CITY = 'London' AND P.PNAME = 'Monitor';` |
