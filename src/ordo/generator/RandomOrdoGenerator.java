package ordo.generator;

import ordo.OrdoInstance;

public class RandomOrdoGenerator extends AbstractOrdoGenerator {

	private int minCost;
	private int maxCost;
	private int minTime;
	private int maxTime;
	
	public RandomOrdoGenerator(int minCost, int maxCost, int minTime, int maxTime) {
		this.minCost = minCost;
		this.maxCost = maxCost;
		this.minTime = minTime;
		this.maxTime = maxTime;
	}

	@Override
	public OrdoInstance generateOrdoInstance(OrdoInstance instance) {
		int maxTime = 0;
		for (int j = 0; j < instance.nbJob; j++) {
			int time = this.random.nextInt(this.maxTime - this.minTime + 1) + this.minTime;
	    	instance.jobTime[j] = time;
	    	maxTime += time;
		}
		for (int j = 0; j < instance.nbJob; j++) {
			for (int t = 0; t < maxTime; t++) {
				int cost = this.random.nextInt(this.maxCost - this.minCost + 1) + this.minCost;
				instance.jobCost[j][t] = cost;
			}
		}
	    return instance;
	}

}
