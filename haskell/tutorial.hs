-- turial code

import Data.Char
import Data.List

-- findKey
findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey key [] = Nothing
findKey key ((k, v): xs)
    | key == k = Just v
    | otherwise = findKey key xs

-- fold version
findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key xs = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing xs
main = putStrLn $ show $ findKey' 1 [(1, 2), (2, 3)]

-- find first N from number list
-- N = "aaa" -> a + a + a
digitSum = sum . map digitToInt . show
findN n = find (\x -> digitSum x == n) [1..]
--main = putStrLn $ show $ findN 15
