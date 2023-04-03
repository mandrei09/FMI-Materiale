
module Printing (showExp) where

import Exp
import Data.List (intercalate)
import System.Win32 (xBUTTON1, SECURITY_ATTRIBUTES (nLength))

showVar :: Var -> String
showVar = undefined

inParens :: String -> String
inParens s = "(" ++ s ++ ")"

showExp :: ComplexExp -> String
showExp (CX x) = showVar x
showExp (Nat n) = show n
showExp (CLam x e) = inParens ("\\" ++ showVar x ++ " ->" ++ showExp e)
showExp (CApp a b) = inParens(showExp a ++ " " ++ showExp b)
showExp (Let x a b) = inParens ("let" ++ showVar x ++ "in" ++ showExp a ++ "in" ++ showExp b)
showExp (LetRec x a b) = inParens ("let" ++ showVar x ++ ":=" ++ showExp a ++ "in" ++ showExp b)
showExp (List e) = inParens ("[" ++ "{" ++ show e ++ "," ++"}" ++ "]")


