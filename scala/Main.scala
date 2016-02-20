
// エラー処理
object Main extends App {
  error

  def error(): Unit = {
    val o: Option[String] = Option("hoge")
    val p = o.get
    print(p)

    val n = Option(null)
    print(n.isEmpty)
    print(n.getOrElse(""))

    // Optionに対するmapとfold
    print(o.map(_ * 3))
    print(o.fold("fuga")(_ * 3))

    // flatten
    val ret = Some(2).map(i1 => Some(3).map(i2 => Some(5).map(i3 => Some(7).map(i4 => Some(11).map(i5 =>
      i1 * i2 * i3 * i4 * i5))))).flatten.flatten.flatten.flatten
    print(ret)
    val ret2 = Some(2).flatMap(i1 => Some(3).flatMap(i2 => Some(5).flatMap(i3 => Some(7).flatMap(i4 => Some(11).map(i5 =>
      i1 * i2 * i3 * i4 * i5)))))
    print(ret2)
    val ret3 = for { i1 <- Some(2)
                     i2 <- Some(5)
                     i3 <- Some(7)} yield i1 * i2 * i3
    print(ret3)

    // Either
    val v1: Either[String, Int] = Right(123)
    val v2: Either[String, Int] = Left("abc")

    val ret4 = v1 match {
      case Right(i) => println(i)
      case Left(s) => println(s)
    }

    println(v1.right.map(_ * 3))
  }
}