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
end