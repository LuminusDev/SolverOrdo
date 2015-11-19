package ordo.generator;

import java.util.Random;

import ordo.OrdoInstance;

public abstract class AbstractOrdoGenerator {
	
	protected Random random;
	
	protected abstract OrdoInstance generateOrdoInstance(OrdoInstance instance);
	
	public AbstractOrdoGenerator(){
		long rgenseed = System.currentTimeMillis();
        System.out.println("Seed used : "+rgenseed);
        this.random = new Random(rgenseed);
	}
	
	public void setSeed(long seed) {
        System.out.println("Seed used : "+seed);
        this.random.setSeed(seed);
    }
	
	public OrdoInstance generate(int nbJob, int nbMachine) {
		OrdoInstance instance = new OrdoInstance(nbJob, nbMachine);
		return this.generateOrdoInstance(instance);
	}
	
}
