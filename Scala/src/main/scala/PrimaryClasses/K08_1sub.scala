package PrimaryClasses

object K08_1sub {
  def GetMaxValue(v1: Int, v2: Int, v3: Int): Int = {
    var temp = if (v1 >= v2) v1 else v2
    temp = if (temp >= v3) temp else v3
    temp
  }

  def GetMinValue(v1: Int, v2: Int, v3: Int): Int = {
    var temp = if (v1 < v2) v1 else v2
    temp = if (temp < v3) temp else v3
    temp
  }
}
