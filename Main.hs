{-# LANGUAGE TypeApplications #-}

module Main where

import Data.List (nub, sort)
import System.Environment (getArgs)

main :: IO ()
main = do
  num <- fmap (read . head) getArgs
  print $ findFactors num

isqrt :: Integer -> Integer
isqrt = floor @Double . sqrt . fromIntegral

findFactors :: Integer -> [Integer]
findFactors n =
  let factorList = filter (\x -> n `mod` x == 0) [2 .. isqrt n]
   in sort . nub $ go [] n factorList
  where
    go :: [Integer] -> Integer -> [Integer] -> [Integer]
    go acc _ [] = acc
    go acc n (x : xs) = go (x : n `div` x : acc) n xs
