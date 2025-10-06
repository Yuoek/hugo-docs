
## video tutor 


{{< tikz width="90%" height="80%" >}}
\begin{tikzpicture}
\draw[fill=yellow] (0.7, 0) -- +(60:2) coordinate (tip) -- +(0:2) -- cycle; 
\begin{scope} [shift=(tip)] 
\draw[help lines, dashed] grid (2, 2); 
\draw[purple, ultra thick] (-1.5, 0) -- (1.5,0) coordinate[pos=0.1] (Alpha) coordinate[pos=0.9] (Beta);
\fill (Alpha) rectangle ++(0.3, 0.3);
\end{scope}
\fill (Beta) rectangle ++(-0.25, 0.25);
\end{tikzpicture}
{{< /tikz >}}


{{< tikz width="90%" height="80%" >}}
\begin{tikzpicture}{ultra thick}
\draw[help lines] grid(6,3);
\coordinate (Alpha) at (1, 1);
\fill[red] (Alpha) circle(3pt);

\end{tikzpicture}
{{< /tikz >}}

