IO.puts "ほげ
from Elixir"

ret = case {1, 2, 3} do
  {1, x, 3} when x > 0 -> "will mutch"
  _ -> "any"
end

IO.puts ret

ret2 = cond do
  2 + 2 == 5 -> "not"
  2 * 2 == 4 -> "true"
  true -> "this is always true"
end

IO.puts ret2


defmodule Math do
  def sum(a, b) do
    a + b
  end

  def zero?(0) do
    true
  end

  def zero?(x) when is_number(x) do
    false
  end
end

IO.puts Math.zero?(0)
IO.puts Math.zero?(199)


defmodule Recursion do
  def print_multiple_times(msg, n) when n <= 1 do
    IO.puts msg
  end

  def print_multiple_times(msg, n) do
    IO.puts msg
    print_multiple_times(msg, n - 1)
  end
end


Recursion.print_multiple_times("Hello", 3)

defmodule MyList do
  def sum_list([head | tail], accumulator) do
    sum_list(tail, head + accumulator)
  end

  def sum_list([], accumulator) do
    accumulator
  end
end

IO.puts MyList.sum_list([1, 2, 3], 0)


IO.puts Enum.reduce([1, 2, 3], 0, &+/2)
IO.puts Enum.map([1, 2, 3], &(&1 * 2))

Enum.map([1, 2, 3], fn x -> x * 2 end)
Enum.map(%{1 => 2, 3 => 4}, fn {k, v} -> k * v end)
