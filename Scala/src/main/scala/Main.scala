import IExecutable.IExecutable
import PrimaryClasses.{FileControl, Sort, K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, Kex, Kex_2}

object Main {

  def ShowSelections(chapter: Int): Unit = {
    if (chapter < 10) {
      for (i <- 1 to 4) {
        printf("\t%d) K0%d_%d\n", i, chapter, i)
      }
      if (chapter == 9) {
        printf("\t5) K0%d_5\n", chapter)
      }
    } else {
      val addedNumber = if (chapter >= 12) {
        chapter + 3
      } else {
        chapter
      }
      for (i <- 1 to 4) {
        printf("\t%d) K%d_%d\n", i, addedNumber, i)
      }
    }
  }

  def main(Args: Array[String]): Unit = {
    val executables: Vector[IExecutable] =
      Vector[IExecutable](new K01, new K02, new K03,
        new K04, new K05, new K06, new K07, new K08,
        new K09, new K10, new K11, new K12, new FileControl)

    println("実行したいプログラムを選択してください。")
    for (i <- 1 to executables.length) {
      if (i < 10)
        printf("%d) K0%d\n", i, i)
      else {
        val addedNumber = if (i >= 12) {
          i + 3
        } else {
          i
        }
        printf("%d) K%d\n", i, addedNumber)
      }
    }
    println("100) Kex")
    println("101) Kex_2")
    println("102) Sort")

    val choice = scala.io.StdIn.readInt
    if (choice == 100) {
      Kex.Execute()
    } else if (choice == 101) {
      Kex_2.Execute()
    } else if (choice == 102) {
      val sort = new Sort
      sort.Execute()
    } else {
      ShowSelections(choice)
      val choice2 = scala.io.StdIn.readInt

      executables(choice - 1).Execute(choice2)
    }
  }
}
