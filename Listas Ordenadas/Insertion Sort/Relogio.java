class Relogio{
    long start;
    long end; 
    long elapsed; // tempo que passou

    public Relogio(){ 
        this.start = 0;
        this.end = 0;
        this.elapsed = 0;
    }


    public long inicio(){
        this.start = System.currentTimeMillis();
        return this.start;
    }

    public long fim(){
        return System.currentTimeMillis();
    }

    public long tempo(){
        
        return this.end-this.start; 
    }

}

