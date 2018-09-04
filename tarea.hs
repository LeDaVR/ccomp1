aprobo :: Float -> Float -> Float -> Bool
aprobo a b c = if (b*0.7+c*0.3>=10.5) && (a<8)
               then True
               else False
main = do
     putStrLn "que sistema operativo usa"
     d <- getLine
     let d = d 
     putStrLn "numero de faltas"
     a <- getLine
     let n = read a :: Float 
     putStrLn "nota dicretas teoria"
     b <- getLine
     let m = read b :: Float
     putStrLn "nota dicretas lab"
     c <- getLine
     let o = read c :: Float
     print (aprobo n m o)
