# YADRO_test_task
Выполнение тестового задания для компании YADRO
1.	Написать на языке С++ класс выполняющий функциональность модулятора QAM (QPSK, QAM16, QAM64)
2.	Написать на языке С++ класс выполняющий функциональность добавления гауссовского шума к созвездию QAM
3.	Написать на языке С++ класс выполняющий функциональность демодулятора QAM (QPSK, QAM16, QAM64)
4.	Написать последовательный вызов 1-3 для случайной последовательности бит для разных значений дисперсия шума
5.	Построить график зависимости вероятности ошибки на бит от дисперсии шума
# Содержимое репозитория
* *QAM_lib*: каталог с исзодными и заголовочными файлами С++ для требуемых классов (п 1-3 задания).
* *without_GUI*: каталог с программой, выполняющей последовательный вызов функций модулятора, AWGN канала и демодулятора (п. 4. задания) и вывод результатов в консоль в виде таблицы.
* *with_GUI*: каталог с программой, написанной в QT, выполняющий построение графика BER/SNR (п 5 задания).
# Использование
**without_GUI:**

Для ос Linux:
```
git clone https://github.com/D-314/YADRO_test_task.git --recurse-submodules
cd YADRO_test_task/without_GUI/
sudo make
./YADRO_test_task
```

Для ос Windows: открыть файл проекта (*CMakeLists.txt* или *test_task_YADRO.pro*) в предпочитаемой IDE, собрать и запустить проект

**with_GUI:**

Открыть файл проекта *test_task_YADRO.pro* в QT Creator, собрать и запустить проект
