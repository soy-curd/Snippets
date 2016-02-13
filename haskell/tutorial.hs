-- turial code

import Data.Char
import Data.List
import qualified Data.Map as Map
import qualified Data.ByteString.Lazy as B
import qualified Data.ByteString as S
import Control.Applicative

-- lazy IO
--main = do
--    contents <- getContents
--    putStr $ map toUpper contents

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

-- Functor
-- fmap :: Functor f => (a -> b) -> f a -> f b
--main = do
--    line <- fmap reverse getLine
--    putStrLn $ "Yout said " ++ line

main = do
    line <- fmap (intersperse '-' . reverse . map toUpper) getLine
    putStrLn line

-- Applicative
a = (*) <$> [1, 2, 3] <*> [1, 2, 3]
b =  liftA2 (:) (Just 3) (Just [4])

-- Monad
c =  ["1"] >>= \x -> return (x)

type Birds = Int
type Pole = (Birds, Birds)

landLeft :: Birds -> Pole -> Maybe Pole
landLeft n (left, right)
    | abs ((left + n) - right) < 4 = Just (left + n, right)
    | otherwise = Nothing

landRight :: Birds -> Pole -> Maybe Pole
landRight n (left, right)
    | abs (left - (right + n)) < 4 = Just (left, right + n)
    | otherwise = Nothing

x -: f = f x

d =  return (1, 3) >>= landLeft 2 >>= landLeft 2 >>= landRight 10

banana :: Pole -> Maybe Pole
banana _ = Nothing

e = return (2, 5) >>= landRight (-1) >>= banana >>= landLeft 1

-- do syntax
foo :: Maybe String
foo = do
    x <- Just 3
    y <- Just "!"
    z <- Nothing
    Just (show x ++ y)

routine :: Maybe Pole
routine = do
    start <- return (0, 0)
    first <- landLeft 2 start
    second <- landRight 2 first
    landLeft 1 second

justH :: Maybe Char
justH = do
    (x:xs) <- Just "hello"
    return x

listOfTuples :: [(Int, Char)]
listOfTuples = do
    n <- [1, 2]
    ch <- ['a', 'b']
    return (n, ch)
