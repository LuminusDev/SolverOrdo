package ordo;

public class OrdoInstance {
	
	// number of job in the instance (j)
	public int nbJob;
	// number of machine in the instance (k)
	public int nbMachine;
	// time of a job [job] (p_j)
	public int[] jobTime;
	// cost of a job at a time [job][time] (c_jt)
	public int[][] jobCost;

	public OrdoInstance(int nbJob, int nbMachine) {
		this.nbJob = nbJob;
		this.nbMachine = nbMachine;
		this.jobTime = new int[nbJob];
		this.jobCost = null;
	}
	
	public void initJobCost(int maxTime) {
		this.jobCost = new int[nbJob][maxTime];
	}

}
