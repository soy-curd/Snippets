-- turial code

import Data.Char
import Data.List
import qualified Data.Map as Map

-- lazy IO
main = do
    contents <- getContents
    putStr $ map toUpper contents

-- hello world
--main = do
--    putStrLn "hello"
--    name <- getLine
--    if null name
--        then return ()
--        else do
--            putStrLn $ reverseWords name
--            main

reverseWords = unwords . map reverse . words

-- Person class
data Person = Person String String Int Float String String
    deriving (Show)

firstName :: Person -> String
firstName (Person firstname _ _ _ _ _) = firstname

-- Record syntax
data Person' = Person' {
    firstName' :: String
    , lastName' :: String
} deriving (Show)

-- Shape culculater
data Shape = Circle Float Float Float | Rectangle Float Float Float Float
    deriving (Show)

area :: Shape -> Float
area (Circle _ _ r) = pi * r ^ 2
area (Rectangle x1 y1 x2 y2) = (abs $ x2 - x1) * (abs $ y2 - y1)

-- findKey
findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey key [] = Nothing
findKey key ((k, v): xs)
    | key == k = Just v
    | otherwise = findKey key xs

-- fold version
findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key xs = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing xs
--main = putStrLn $ show $ findKey' 1 [(1, 2), (2, 3)]

-- find first N from number list
-- N = "aaa" -> a + a + a
digitSum = sum . map digitToInt . show
findN n = find (\x -> digitSum x == n) [1..]
--main = putStrLn $ show $ findN 15
