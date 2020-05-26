# onemoretask
Как из мухи сделать слона

Необходимо реализовать алгоритм решения задачи «Как из мухи сделать слона». Реализацию необходимо предоставить в виде исходного кода консольного приложения. Реализация приложения должна проходить в соответствии c технологией разработки TDD. Стиль написания кода должен соответствовать Camel notation, код логик и тестов должен быть качественно закомментирован. Любые оптимизации решения считаются преимуществом. В пояснительной записке к решению необходимо указать, какому шаблону проектирования оно соответствует.

Постановка задачи
Дано исходное и конечное слово равной длины. Длина исходных слов не ограничена. Необходимо составить цепочку слов от исходного слова до конечного. Каждое следующее слово в цепочке может отличаться от предыдущего только одной буквой. Исходное, конечное и все промежуточные слова должны состоять из одинакового количества букв. Все используемые слова обязательно должны содержаться в заранее определенном словаре.
На вход в программу подается:

1. Путь к текстовому файлу, в котором указано начальное и конечное слово. На первой строке указано начальное слово, на второй строке конечное
2. Путь к файлу, который содержит словарь. Слова в словаре указаны по одному на каждой строке. В словаре слова могут быть разной длины.

На выходе программа должна вывести в консоль путь от исходного слова к конечному, по одному слову на одной строке.

Пример 
Начальное слово: КОТ
Конечное слово: ТОН
Словарь:
КОТ
ТОН
НОТА
КОТЫ
РОТ
РОТА
ТОТ

Решение
КОТ
ТОТ
ТОН
