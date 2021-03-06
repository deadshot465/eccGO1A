from strutils import parseInt
import IExecutable, K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, Kex, FileControl

proc show_selections(chapter: int) =
    if chapter < 10:
        for i in 1..4:
            echo "\t", i, ") K0", chapter, "_", i
        if chapter == 9:
            echo "\t5) K0", chapter, "_5"
    else:
        for i in 1..4:
            echo "\t", i, ") K", chapter, "_", i

var executables: seq[IExecutable]
executables.add(K01())
executables.add(K02())
executables.add(K03())
executables.add(K04())
executables.add(K05())
executables.add(K06())
executables.add(K07())
executables.add(K08())
executables.add(K09())
executables.add(K10())
executables.add(K11())
executables.add(FileControl())

echo "実行したいプログラムを選択してください。"

for i in countup(1, executables.len):
    echo i, ") K0", i
echo "100) Kex"

var choice = parseInt(readLine(stdin))
if choice == 100:
    var kex = Kex()
    kex.execute
else:
    show_selections(choice)
    var choice2 = parseInt(readLine(stdin))
    executables[choice - 1].execute(choice2)